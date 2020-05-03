#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE 80  /* Maximum presumed command length */

/* Node that represents a memory block:
*  Holds the ID of the proccess and a memory range.
*  ID = -1 if its an empty hole in memory */
struct node {
	int pid;
	int start;
	int end;
	struct node *next;
	struct node *prev;
};

/* Main memory management functions */
int request(struct node *head, int pid, int size, char strat);
int release(struct node *head, int pid);
struct node *compact(struct node *head, int max);
int report(struct node *head);

/* Memory-allocation strategy functions */
struct node *find_first_fit(struct node *head, int size);
struct node *find_best_fit(struct node *head, int size);
struct node *find_worst_fit(struct node *head, int size);

/* Utility functions */
int get_command(char *cmd[MAX_LINE]);
void insert_node(struct node *reference, struct node *new_node);
void clear_list(struct node *head);
struct node *append_node(struct node *head, struct node *new_node);
struct node *create_node(int pid, int start, int end, 
			struct node *next, struct node *prev);

int main(int argc, char const *argv[])
{
	int max = atoi(argv[1]); /* Total memory size */
	char *cmd[MAX_LINE];     /* Command args. Ends with NULL. */

	/* Initialize double linked list head */
	struct node *head = create_node(-1, 0, max - 1, NULL, NULL);

	/* Start program */
	int found;
	int argsize;
	int run = 1;
	while(run) {
		/* Get command */
		printf("allocator>");
		argsize = get_command(cmd);

		/* Memory operations */
		if (!strcmp(cmd[0], "C")) {
			/* Compact unused holes into one */
			head = compact(head, max);
		} else if (!strcmp(cmd[0], "RQ")) {
			/* Request block for 1 proccess */
			cmd[1][0] = '0'; /* Remove the "P" from the pid */
			request(head, atoi(cmd[1]),
				atoi(cmd[2]), cmd[3][0]);
		} else if (!strcmp(cmd[0], "RL")) {
			/* Release block for 1 proccess */
			cmd[1][0] = '0'; /* Remove the "P" from the pid */
			found = 0;
			while (release(head, atoi(cmd[1]))) {
				found = 1;
			}
			if (!found)
				printf("Fail to release P%d\n", atoi(cmd[1]));
		} else if (!strcmp(cmd[0], "STAT")) {
			/* Report memory status */
			report(head); 
		} else if (!strcmp(cmd[0], "X")) {
			/* Flag to end program */
			run = 0; 
		}

		/* Memory clearing */
		for (int i = 0; i <= argsize; i++)
			free(cmd[i]);
	}

	clear_list(head);
	return 0;
}

/* Requests a memory block based on a certain strategy */
int request(struct node *head, int pid, int size, char strat)
{
	/* Can't ask for 0 or negative memory */
	if (size <= 0) {
		printf("The request of P%d fail\n", pid);
		return 0;
	}

	/* Perform strategy to find section */
	struct node *found;
	if (strat == 'F') {
		/* Find first-fit block */
		found = find_first_fit(head, size);
	} else if (strat == 'B') {
		/* Find best-fit block */
		found = find_best_fit(head, size);
	} else if (strat == 'W') {
		/* Find worst-fit block */
		found = find_worst_fit(head, size);
	}

	/* Section not found */
	if (found == NULL) {
		printf("The request of P%d fail\n", pid);
		return 0;
	}

	/* Section found: Allocate memory for proccess */
	int hole_end = found->end;
	found->end = found->start + size - 1;
	found->pid = pid;

	/* Empty hole left: Create a node representing the hole 
	* It will be inserted directly after the FOUND allocated section */
	if (hole_end > found->end) {
		int hole_start = found->end + 1;
		struct node *hole;
		hole = create_node(-1, hole_start, hole_end, NULL, NULL);
		insert_node(found, hole);
	}
	return 1;
}

/* Returns the first-found viable memory section */
struct node *find_first_fit(struct node *head, int size)
{
	/* Traverse list */
	int section;
	struct node *curr = head;
	while(curr != NULL) {
		/* If empty section satisfies size */
		section = (curr->end - curr->start + 1);
		if (curr->pid == -1 && size <= section) {
			break; /* Found the first-fit */
		}
		curr = curr->next;
	}
	return curr;
}

/* Returns the smallest viable memory section */
struct node *find_best_fit(struct node *head, int size)
{
	/* Traverse list */
	int section;
	struct node *best = NULL;
	struct node *curr = head;
	while(curr != NULL) {
		/* If empty section satisfies size */
		section = (curr->end - curr->start + 1);
		if (curr->pid == -1 && size <= section) {
			if (best == NULL) {
				best = curr;
			} else if (section < (best->end - best->start + 1)) {
				best = curr;
			}
		}
		curr = curr->next;
	}
	return best;
}

/* Returns the largest viable memory section */
struct node *find_worst_fit(struct node *head, int size)
{
	/* Traverse list */
	int section;
	struct node *worst = NULL;
	struct node *curr = head;
	while(curr != NULL) {
		section = (curr->end - curr->start + 1);
		/* If empty section satisfies size */
		if (curr->pid == -1 && size <= section) {
			if (worst == NULL) {
				worst = curr;
			} else if (section > (worst->end - worst->start + 1)) {
				worst = curr;
			}
		}
		curr = curr->next;
	}
	return worst;
}

int release(struct node *head, int pid)
{
	/* Traverse list */
	int found = 0;
	struct node *curr = head;
	while(curr != NULL) {
		if (curr->pid == pid) {
			found = 1;
			break;
		}
		curr = curr->next;
	}

	/* Not found on the first time: Does not exist */
	if (!found) {
		return 0;
	}

	/* Found the node: mark space as empty */
	curr->pid = -1;

	/* Now check for adjacent holes. 
	*  Merge them keeping the head intact */
	struct node *tmp_next = curr->next;
	if (tmp_next != NULL) {
		if (tmp_next->pid == -1) {
			/* NEXT EMPTY: Merge next into curr node. 
			*  And reconnect linked list */
			curr->end = tmp_next->end;
			if (tmp_next->next != NULL) {
				tmp_next->next->prev = curr;
				curr->next = curr->next->next;
			} else {
				curr->next = NULL;
			}
			free(tmp_next);
		}
	}

	struct node *tmp_prev = curr->prev;
	if (tmp_prev != NULL) {
		if (tmp_prev->pid == -1) {
			/* PREV EMPTY: Merge curr into prev node.
			*  And reconnect linked list */
			tmp_prev->end = curr->end;
			if (curr->next != NULL) {
				curr->next->prev = tmp_prev;
			}
			tmp_prev->next = curr->next;
			free(curr);
		}
	}
	return 1;
}

/* Prints out a report of the current memory status */
int report(struct node *head)
{
	/* Empty list: return error */
	if (head == NULL)
		return 0;

	/* Traverse */
	struct node *curr = head;
	while(curr != NULL) {
		if (curr->pid == -1) {
			printf("Addresses [%d:%d] Unused\n",
				curr->start,
				curr->end);
		} else {
			printf("Addresses [%d:%d] Process P%d\n",
				curr->start,
				curr->end,
				curr->pid);
		}
		curr = curr->next;
	}
	return 1;
}

/* Puts all proccess sections in one side
*  And merge all the holes on the other */
struct node *compact(struct node *head, int max)
{
	/* Create new list */
	struct node *new_head = NULL;

	/* Traverse main list and transfer contents
	*  Allocated blocks go to the top */
	int range;
	struct node *new;
	struct node *last = NULL;
	struct node *curr = head;
	while (curr->next != NULL) {
		if (curr->pid != -1) {
			if (last == NULL) {
				/* First node */
				range = curr->end - curr->start;
				new = create_node(curr->pid, 0,
						range, NULL, NULL);
			} else {
				range = curr->end - curr->start;
				new = create_node(curr->pid, last->end + 1,
						last->end + 1 + range, 
						NULL, NULL);
			}
			new_head = append_node(new_head, new);
			last = new;
		}
		curr = curr->next;
	}

	/* NOTHING TO COMPACT: No changes needed. */
	if (last == NULL) {
		return head;
	} 

	/* Processes transferred successfully
	*  Add the EMPTY SPACE HOLE node at the end */
	new = create_node(-1, last->end + 1, max - 1, NULL, NULL);
	new_head = append_node(new_head, new);
	
	/* Clear previous list */
	clear_list(head);
	return new_head;
}

/* Free all nodes from heap */
void clear_list(struct node *head)
{
	struct node *tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

struct node *create_node(int pid, int start, int end, 
			 struct node *next, struct node *prev)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	/* Copy values */
	new_node->pid = pid;
	new_node->start = start;
	new_node->end = end;
	new_node->next = next;
	new_node->next = prev;

	return new_node;
}

/* Inserts a node at the end of the list */
struct node *append_node(struct node *head, struct node *new_node)
{
	if (head == NULL) {
		head = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	} else {
		struct node *curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new_node;
		new_node->next = NULL;
		new_node->prev = curr;
	}

	return head;
}

/* Inserts a new node after a specified reference node */
void insert_node(struct node *reference, struct node *new_node)
{	
	/* Position the new node after the reference */
	new_node->prev = reference;
	new_node->next = reference->next;
	if (reference->next != NULL) {
		reference->next->prev = new_node;
	}
	reference->next = new_node;
}

/* Gets keyboard input, parses args into array, and returns its size. */
int get_command(char *cmd[MAX_LINE])
{
	/* Get command input into temporary buffer */
	char buffer[MAX_LINE];

	fgets(buffer, MAX_LINE, stdin);
	for (int i = 0; ; i++) {
		if (buffer[i] == '\n') {
			buffer[i] = '\0';
			break;
		}
	}

	/* Parse buffer args into the command array */
	int size;
	int pos = 0;
	char *pc = strtok(buffer, " ");

	while (pc != NULL) {
		/* Size count */
		size = 0;
		for (int i = 0; ; i++) {
			size++;
			if (pc[i] == '\0')
				break;
		}

		/* Allocate memory for the arg and copy it */
		cmd[pos] = malloc(size * sizeof(char));
		strcpy(cmd[pos], pc);

		/* Advance to next arg */
		pc = strtok(NULL, " ");
		pos++;
	}

	/* set NULL terminator and return argsize */
	cmd[pos] = NULL;
	return pos;
}