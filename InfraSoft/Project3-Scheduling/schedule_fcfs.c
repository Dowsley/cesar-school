#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "schedulers.h"
#include "task.h"
#include "cpu.h"
#include "list.h"

struct node* head = NULL;

// add a task to the list (in this case, a queue)
void add(char *name, int priority, int burst)
{
        Task* task = malloc(sizeof(Task));
        task->priority = priority;
        task->burst = burst;
        task->name = malloc(strlen(name)+1 * sizeof(char)); // +1 because of the \0
        strcpy(task->name, name);

        insert(&head, task);
}

// FIFO (Queue)
Task* pickNextTask()
{
        if (head)
        {
                struct node* curr = head;
                while (curr->next) // While not last element
                {
                        curr = curr->next; // Skip to the next
                }
                return curr->task;
        }
        else return NULL; // Empty list
}

// Returns integer size of linked list
int getSize(struct node *head)
{
        int size = 0;
        struct node* temp= head;
        while (temp != NULL) 
        {
                temp = temp->next;
                size++;
        }
        return size;
}


// invoke the scheduler (arrival time 0)
void schedule()
{
        int elapsed_time = 0;  // Simulated time  
        int n = 0;             // Task number (array position)

        int s = getSize(head); // List size
        int tat[s];            // Turn around times
        int wt[s];             // Waiting times (equals response time)
        char tnames[s][50];    // Task names string array

        FILE* fp = fopen("fcfs.txt","w"); // File output
        fprintf(fp,"EXECUTION BY FCFS\n");

        Task* task;
        while(head)
        {
                task = pickNextTask();
                wt[n] = elapsed_time;
        
                run(task, task->burst);
                elapsed_time += task->burst;
                tat[n] = elapsed_time;
                strcpy(tnames[n],task->name);

                fprintf(fp,"\n[%s] for %d units",tnames[n], task->burst);
                delete(&head,task);
                n++;
        }  

        // Average variables
        float sum_tat = 0;
        float sum_wt = 0;

        fprintf(fp,"\n\nMETRICS\n");
        for (int i = 0; i < s; i++)
        {
                fprintf(fp,"\n[%s]\n",tnames[i]);
                fprintf(fp,"Turnaround time: %d\n", tat[i]);
                fprintf(fp,"Waiting time: %d\n",wt[i]);
                fprintf(fp,"Response time: %d\n",wt[i]);
                sum_tat += tat[i];
                sum_wt += wt[i];
        }

        fprintf(fp, "\nAverage turnaround time = %.2f",sum_tat/s);
        fprintf(fp, "\nAverage waiting time = %.2f",sum_wt/s);
        fprintf(fp, "\nAverage response time = %.2f",sum_wt/s);

        fclose(fp);  
}