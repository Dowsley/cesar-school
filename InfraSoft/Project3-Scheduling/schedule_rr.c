#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "schedulers.h"
#include "task.h"
#include "cpu.h"
#include "list.h"

struct task_m{
    char *name;
    int burst;
    int remaining_burst;
    int waiting_time;
    // Turnaround time = burst + waiting time
};

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
int getSize(struct node* head)
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

// Copies the list of tasks to the metrics array.
void createMetrics(struct task_m* metrics, struct node* head)
{
        int i = 0;
        struct node* temp= head;
        while (temp != NULL) 
        {
                metrics[i].name = malloc(strlen(temp->task->name)+1 * sizeof(char));
                strcpy(metrics[i].name,temp->task->name);
                metrics[i].remaining_burst = temp->task->burst;
                metrics[i].waiting_time = 0;
                metrics[i].burst = temp->task->burst;
                temp = temp->next; // Goes to the next
                i++;
        }
}

// Searches and returns tasks metrics by name.
struct task_m* getTaskMetric(struct task_m* metrics, int size, char* name)
{
        // Search the metrics array
        for (int i = 0; i < size; i++)
        {
                if (!strcmp(metrics[i].name, name)) // Found it
                        return &metrics[i];
        }
        return NULL;
}

// invoke the scheduler (arrival time 0)
void schedule()
{
        int size = getSize(head);
        struct task_m* metrics = malloc(size * sizeof(struct task_m));
        createMetrics(metrics, head);

        FILE* fp = fopen("rr.txt","w"); // File output
        fprintf(fp,"EXECUTION BY RR\n");

        struct task_m* metric; // Temporary adress holder
        Task* task;            // Temporary adress holder
        int temp_priority;       

        int t = 0;             // Elapsed time 
        while(head)
        {
                task = pickNextTask();
                metric = getTaskMetric(metrics,size,task->name);
                if (metric->remaining_burst > QUANTUM) // Cycle still goes
                {
                        run(task, QUANTUM);
                        fprintf(fp,"\n[%s] for %d units",task->name, QUANTUM);

                        t += QUANTUM;                       // Step time by 1 QUANTUM STEP
                        metric->remaining_burst -= QUANTUM; // Decrease remaining burst 

                        // Proccess still needs to be executed again.
                        temp_priority = task->priority;
                        delete(&head,task); // Deletes before. IMPORTANT.
                        add(metric->name,temp_priority,metric->burst);
                }
                else // Last cycle of this task
                {
                        run(task,metric->remaining_burst);
                        fprintf(fp,"\n[%s] for %d units",task->name, metric->remaining_burst);

                        // Advance time by burst time left
                        t += metric->remaining_burst;
                        
                        // Waiting time = current time minus original burst
                        metric->waiting_time = t - task->burst;

                        // Proccess is fully executed.
                        delete(&head,task);    
                }
        }  

        // Average variables
        float sum_tat = 0;
        float sum_wt = 0;

        fprintf(fp,"\n\nMETRICS\n");
        for (int i = 0; i < size; i++)
        {
                fprintf(fp,"\n[%s]\n",metrics[i].name);
                fprintf(fp,"Turnaround time: %d\n", metrics[i].burst + metrics[i].waiting_time);
                fprintf(fp,"Waiting time: %d\n", metrics[i].waiting_time);
                fprintf(fp,"Response time: %d\n", metrics[i].waiting_time);
                sum_tat += metrics[i].burst + metrics[i].waiting_time;
                sum_wt += metrics[i].waiting_time;
        }

        fprintf(fp, "\nAverage turnaround time = %.2f",sum_tat/size);
        fprintf(fp, "\nAverage waiting time = %.2f",sum_wt/size);
        fprintf(fp, "\nAverage response time = %.2f",sum_wt/size);

        fclose(fp);  
}