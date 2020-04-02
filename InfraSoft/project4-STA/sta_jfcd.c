#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Is TA sleeping?
pthread_mutex_t mutex_sleep;
int is_sleeping;

// Controls access to the 3 waiting chairs.
pthread_mutex_t mutex_chairs;
int used_chairs;

// Controls access to the number of active students (tasks).
pthread_mutex_t mutex_stds;
int active_students;

sem_t sem_ta_room;  // Signal for TA's room access.
sem_t sem_ta_sleep; // Signal for TA sleep 
sem_t sem_std;      // Signal for student assistance end

void log_msg(int pid, char *msg)
{
        printf("\n[%d] %li: %s", pid, time(NULL), msg);
}

// Simulates TA assistance as a task.
void *ta_task(void *arg)
{
        int randtime = rand() % 10;
        int tmp;
        while (1) {
                // Waiting for student to awaken him...
                /*pthread_mutex_lock(&mutex_sleep);
                is_sleeping = 1;
                pthread_mutex_unlock(&mutex_sleep);*/
                printf("\nTA is sleeping.");

                sem_wait(&sem_ta_sleep);
                printf("\nTA has been awakened by a student.");
                /*pthread_mutex_lock(&mutex_sleep);
                is_sleeping = 0;
                pthread_mutex_unlock(&mutex_sleep);*/
                
                // awake cycle
                while (1) {
                        sem_post(&sem_ta_room); // Notify students that the room is free.

                        pthread_mutex_lock(&mutex_chairs);
                        tmp = --used_chairs;    // Student leaves the chair
                        pthread_mutex_unlock(&mutex_chairs);

                        sleep(randtime);        // Assisting student...
                        sem_post(&sem_std);     // Notify that assistance is over
                        
                        pthread_mutex_lock(&mutex_stds);
                        active_students--;
                        if (active_students == 0) {
                                printf("\nThere is no more students to help. TA left the room.");
                                return NULL;
                        }
                        pthread_mutex_unlock(&mutex_stds);

                        // Check if there are students left.
                        if (tmp == 0) {
                                printf("\nTA went back to sleep."); 
                                break;
                        }
                }
        }
}

// Simulates student as a task. Gets student number as unique arg.
void *student_task(void *arg)
{
        int n = *(int *) arg;
        int tmp;
        int randtime = rand() % 19;
        while(1) {
                // Entry section (Student programming)
                sleep(randtime);
        
                // Check for available chairs and take action (Critical section)
                printf("\nStudent #%d is going to TA room (after waiting %d)", n,randtime);
                pthread_mutex_lock(&mutex_chairs);
                if (used_chairs < 3) {
                        if (used_chairs == 0) { //log_msg(n, "[[ALL CHAIRS ARE FREE]]");
                                // CASE 1: Empty line, doesnt wait or occupy chair
                                used_chairs++;
                                pthread_mutex_unlock(&mutex_chairs);
                        } else { //log_msg(n, "[[AT LEAST ONE CHAIR FREE]]");
                                // CASE 2: Free chair, sits and wait for TA room to free up
                                used_chairs++;
                                pthread_mutex_unlock(&mutex_chairs);
                                printf("\nStudent #%d sat on chair #%d. %d chair(s) remain.",
                                        n,used_chairs,3-used_chairs);
                                sem_wait(&sem_ta_room);
                        }
                        // Is he sleeping?
                        pthread_mutex_lock(&mutex_sleep);
                        /*if (is_sleeping) {
                                printf("\nStudent #%d is awaking the TA.", n);
                        }*/
                        pthread_mutex_unlock(&mutex_sleep);
                        sem_post(&sem_ta_sleep); // Notifies TA (wake him up)
                        printf("\nStudent #%d is getting inside TA room.",n);
                        sem_wait(&sem_std);      // Waits for own assistance to finish
                        printf("\nTA finished teaching student #%d.",n);
                        printf("\nStudent #%d left TA room.",n);

                        // EXIT POINT
                        return NULL;
                } else { //log_msg(n, "[[NO CHAIRS AVAILABLE]]");
                        // CASE 3: Goes back to programming
                        pthread_mutex_unlock(&mutex_chairs);
                        printf("\nThere is no available chair to student %d. The student will return late.", n);
                }
        }
}

int main(int argc, char const *argv[])
{
        int n = atoi(argv[1]); // Number of students
        active_students = n;
        used_chairs = 0; 
        
        int stds_num[n];       // Student numbers (identifiers)
        pthread_t stds_tid[n]; // Student's tids
        pthread_t ta;

        pthread_mutex_init(&mutex_chairs, NULL);
        pthread_mutex_init(&mutex_sleep, NULL);
        pthread_mutex_init(&mutex_stds, NULL);

        sem_init(&sem_ta_sleep, 0, 0);
        sem_init(&sem_ta_room, 0, 0);
        sem_init(&sem_std, 0, 0);


        // Run tasks
        pthread_create(&ta,NULL,ta_task,NULL);
        for (int i = 1; i<=n; i++) {
                stds_num[i] = i;
                pthread_create(&stds_tid[i],NULL,student_task,(void *) &stds_num[i]);
        }

        // Join tasks
        for (int i = 1; i<=n; i++) {
                pthread_join(stds_tid[i], NULL);
        }
        pthread_join(ta, NULL);
        
        return 0;
}