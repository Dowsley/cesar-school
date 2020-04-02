#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

// TODO - Fflushes
// TODO - /* comments */ 

// Controls access to number of chairs taken.
pthread_mutex_t mutex_chairs;
int used_chairs = 0;
int c = 0; // Goes from 0 to 2 (Chair index)

// Controls access to the number of active students (tasks).
pthread_mutex_t mutex_stds;
int active_students;

sem_t sem_ta_sleep;   // Signal for TA sleep 
sem_t sem_std;        // Signal for student assistance end
sem_t sem_chairs[3];  // Signal for chair call.

int waking_student;  /* Who woke up the TA */
int sitting_student; /* Who got in the seat */


void log_msg(int pid, char *msg)
{
        printf("[%d] %li: %s\n", pid, time(NULL), msg);
}

// Simulates TA assistance as a task.
void *ta_task(void *arg)
{
        //int randtime;
        printf("TA is sleeping.\n");
        while (1) {
                // Waiting for student to awaken him...
                sem_wait(&sem_ta_sleep);
                printf("Student #%d is awaking the TA.\n", waking_student); // UNSTABLE: Global
               
                // awake cycle
                while (1) {

                        // Check if there is any student waiting.
                        pthread_mutex_lock(&mutex_chairs);
                        if (used_chairs == 0) {
                                pthread_mutex_unlock(&mutex_chairs);
                                printf("TA went back to sleep.\n"); 
                                break;
                        }

                        sem_post(&sem_chairs[c]); // Notify students that the room is free.
                        used_chairs--;
                        //printf("Student left his/her chair. Remaining Chairs %d\n", 3 - used_chairs);
                        c = (c + 1) % 3;
                        pthread_mutex_unlock(&mutex_chairs);


                        sleep(rand() % 5 + 1);  // Assisting student...
                        sem_post(&sem_std);     // Notify that assistance is over

                        // Check if all students were assisted.
                        pthread_mutex_lock(&mutex_stds);
                        active_students--;
                        sleep(1);
                        if (active_students == 0) {
                                printf("There is no more students to help. TA left the room.\n");
                                return NULL;
                        }
                        pthread_mutex_unlock(&mutex_stds);
                }
        }
}

// Simulates student as a task. Gets student number as unique arg.
void *student_task(void *arg)
{
        int id = *(int *) arg;
        int randtime;
        while(1) {
                // Entry section (Student programming)
                randtime = rand() % 5 + 1;
                sleep(randtime);

                // Check for available chairs and take action (Critical section)
                printf("Student #%d is going to TA room (after waiting %d)\n", id ,randtime); // TODO :  - rm debug

                pthread_mutex_lock(&mutex_chairs);
                int tmp = used_chairs;
                pthread_mutex_unlock(&mutex_chairs);
        
                if (tmp < 3) {
                        if (tmp == 0) {
                                // CASE 1: Empty chairs. Wake up TA.
                                waking_student = id;
                                sem_post(&sem_ta_sleep); // Notifies TA (wake him up)

                        } else {
                                // CASE 2: Free chair, sits and wait for TA room to free up
                                printf("Student %d sat on a chair waiting for the TA to finish. \n", id); // FIXME: FOREIGN

                        }

                        pthread_mutex_lock(&mutex_chairs);
                        int index = (c + used_chairs) % 3;
                        used_chairs++;
                        printf("Student sat on chair. Chairs Remaining: %d\n", 3 - used_chairs); // FIXME: FOREIGN
                        pthread_mutex_unlock(&mutex_chairs);

                        sem_wait(&sem_chairs[index]);  // Waits for TA to call.
                        printf("Student %d is getting help from the TA.\n", id);
                        
                        // Waits for own assistance to finish
                        sem_wait(&sem_std);
                        printf("TA finished teaching student #%d.\n", id);
                        printf("Student #%d left TA room.\n", id);

                        // EXIT POINT
                        return NULL;
                } else {
                        // CASE 3: Goes back to programming
                        printf("There is no available chair to student %d. The student will return late.\n", id);
                }
        }
}

int main(int argc, char const *argv[])
{
        int n = atoi(argv[1]); // Number of students
        active_students = n;
	pthread_t stds_tid[n];
        pthread_t ta;
        

        srand(time(NULL));

        // Initialize signalers
        sem_init(&sem_ta_sleep, 0, 0);
        sem_init(&sem_std, 0, 0);
        for (int i = 0; i<3; i++) {
                sem_init(&sem_chairs[i], 0, 0);
        }
        pthread_mutex_init(&mutex_chairs, NULL);
        pthread_mutex_init(&mutex_stds, NULL);

        // Run tasks
        int stds_num[n];
        pthread_create(&ta,NULL,ta_task,NULL);
        for (int i = 1; i<=n; i++) {
                stds_num[i] = i;
                pthread_create(&stds_tid[i],NULL,student_task,(void *) &stds_num[i]);
        }

        // Join tasks
        pthread_join(ta, NULL);
        for (int i = 1; i<=n; i++) {
                pthread_join(stds_tid[i], NULL);
        }

        return 0;
}