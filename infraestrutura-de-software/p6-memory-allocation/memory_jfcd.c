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
int compact();
int report(struct node *head);

/* Memory strategies functions */
struct node *find_first_fit(struct node *head, int size);
struct node *find_best_fit(struct node *head, int size);
struct node *find_worst_fit(struct node *head, int size);

/* Double linked list functions */
void *insert_node(struct node *head, struct node *new_node, int pid);
struct node *create_node(int pid, int start, int end, 
			 struct node *next, struct node *prev);

/* Utility functions */
int get_command(char *cmd[MAX_LINE]);

int main(int argc, char const *argv[])
{
	int max = atoi(argv[1]); /* Total memory size */
	char *cmd[MAX_LINE];     /* Command args. Ends with NULL. */

	/* Initialize double linked list head */
	struct node *head = create_node(-1, 0, max-1, NULL, NULL);

	/* Start program */
	int argsize;
	int run = 1;
	while(run) {
		/* Get command */
		printf("allocator>");
		argsize = get_command(cmd);

		/* Memory operations */
		if (!strcmp(cmd[0], "C")) {
			/* Compact unused holes into one */
			//compact();
		} else if (!strcmp(cmd[0], "RQ")) {
			/* Request block for 1 proccess */
			cmd[1][0] = '0'; /* Remove the "P" from the pid */
			request(head, atoi(cmd[1]),
				atoi(cmd[2]), cmd[3][0]);
		} else if (!strcmp(cmd[0], "RL")) {
			/* Release block for 1 proccess */
			cmd[1][0] = '0'; /* Remove the "P" from the pid */
			release(head, atoi(cmd[1]));
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

	return 0;
}

int request(struct node *head, int pid, int size, char strat)
{
	/* Perform strategy to find section */
	struct node *found;
	if (strat == 'F') {
		/* Find first-fit block */
		found = find_first_fit(head, size);
	} else if (strat == 'B') {
		/* Find best-fit block */
		//found = find_best_fit(head, size);
	} else if (strat == 'W') {
		/* Find worst-fit block */
		//found = find_worst_fit(head, size);
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
		insert_node(head, hole, found->pid);
	}
	return 1;
}

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

struct node *find_best_fit(struct node *head, int size)
{
	//TODO
	return NULL;
}

struct node *find_worst_fit(struct node *head, int size)
{
	//TODO
	return NULL;
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

	/* Not found */
	if (!found) {
		printf("Fail to release P%d", pid);
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

/* Inserts a new node after a specified node */
void *insert_node(struct node *head, struct node *new_node, int pid)
{
	/* Traverse */
	struct node *curr = head;
	while(curr->next != NULL) {
		if (curr->pid == pid)
			break; /* Found the specified node */
		curr = curr->next;
	}
	
	/* Position the new node after it */
	new_node->prev = curr;
	new_node->next = curr->next;
	curr->next = new_node;
}

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

/* Gets keyboard input, parses args into array, and returns its size. */
int get_command(char *cmd[MAX_LINE])
{
	/* Get command input into temporary buffer */
	char buffer[MAX_LINE];

	fflush(stdin); // TODO: Replace this, causes undefined behavior
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