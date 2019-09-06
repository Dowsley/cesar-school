#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	int id;
	struct node* next;
}node;

typedef struct master{
	node* end;
	node* start;
}master;

void addNode(master*, int);
void display (master*);

int main()
{
	int n;   // Inputs
	int m;   // Outputs
	int new_id;
	int old_id;

	master Master = NULL;

	scanf("%d", &n);
	for (n; n > 0; n--)
	{
		scanf("%d", &new_id);
		addNode(&Master, new_id);
	}

/*	scanf("%d", &m)
	for (m; m > 0; m--)
	{
		scanf("%d", &old_id);
		rmNode(&Master, old_id);
	}	*/

	return 0;
}


void addNode(master* Master, int new_id)
{
	node* new_node = malloc(sizeof(node*))
	new_node->id = new_id;
	new_node->next = NULL;

	if (*Master == NULL){
		Master->end = new_node;
		Master->start = new_node;
	}

	else{
		new_node->next = Master->end;
		Master->end = new_node;
	}
}



/*void rmNode(*master Master, int old_id)
{

}*/



void displayQueue(master* Master)
{
	node* atual = Master->end;
	while (atual->next != NULL)
		printf("%d \n", atual->id);

}