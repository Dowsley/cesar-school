#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    int pid;
    int start;
    int end;
    struct node *next;
    struct node *prev;
};

struct node *insert(struct node *head, int pid, int start, int end)
{
        /* Create new node */
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->pid = pid;
        new_node->start = start;
        new_node->end = end;
        new_node->next = NULL;
        
        if (head == NULL) {
                /* Pre-pend as first node */
                head = new_node;
                head->prev = NULL;
        } else {
                /* Find last node */
                struct node *prev;
                struct node *curr = head;
                while(curr->next != NULL) {
                        prev = curr;
                        curr = curr->next;
                }
                /* Found: APPEND new node */
                curr->next = new_node;
                curr->prev = prev;
        }
        return head;
}

void traverse(struct node *head)
{
        if (head != NULL) {
                struct node *curr = head;
                while(curr->next != NULL) {
                        printf("\nAddresses [%d:%d] Process P%d",
                                curr->start,
                                curr->end,
                                curr->pid);
                        curr = curr->next;
                }
        }
}

int main(int argc, char const *argv[])
{
    struct node *head = NULL;

    head = insert(head, 0, 0, 1000);
    head = insert(head, 1, 1001, 2000);
    head = insert(head, 2, 2001, 3000);
    head = insert(head, 3, 3001, 4000);
    traverse(head);
    return 0;
}
