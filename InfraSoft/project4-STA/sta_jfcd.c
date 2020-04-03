#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

pthread_mutex_t mutex_chairs; /* Controls access to number of chairs taken.*/
int used_chairs = 0;
int c = 0; /* Chair index offset on array */

pthread_mutex_t mutex_stds; /* Controls access to the number of active students (tasks).*/
int active_students;

sem_t sem_ta_sleep;   /* Signal for TA sleep */
sem_t sem_std;        /* Signal for ending student's assistance */
sem_t sem_chairs[3];  /* Signal for chair call. */

int waking_student;  /* Who woke up the TA */


void log_msg(int pid, char *msg)
{
        printf("[%d] %li: %s\n", pid, time(NULL), msg);
        fflush(stdout);
}


/* Simulates TA as a running thread (task) */
void *ta_task(void *arg)
{
        printf("TA is sleeping.\n");
        while (1) {
                /* Waiting for student to awaken him */
                sem_wait(&sem_ta_sleep);
                printf("Student #%d is awaking the TA.\n", waking_student); /* UNSTABLE: Global */
                fflush(stdout);
               
                /* Awake cycle */
                while (1) {

                        /* Check if there is any student waiting. */
                        pthread_mutex_lock(&mutex_chairs);
                        if (used_chairs == 0) {
                                pthread_mutex_unlock(&mutex_chairs);
                                printf("TA went back to sleep.\n");
                                fflush(stdout);
                                break;
                        }

                        sem_post(&sem_chairs[c]); /* Notify students that the room is free. */
                        used_chairs--;
                        c = (c + 1) % 3; /* Increment the chair index offset */
                        pthread_mutex_unlock(&mutex_chairs);


                        sleep(rand() % 5 + 1); /* Assisting student */
                        sem_post(&sem_std);     /* Notify that assistance is over */

                        /* Check if all students were assisted. */
                        pthread_mutex_lock(&mutex_stds);
                        active_students--;
                        if (active_students == 0) {
                               return NULL;
                        }
                        pthread_mutex_unlock(&mutex_stds);
                }
        }
}


/* Simulates student as a running task. Gets student id as unique arg. */
void *student_task(void *arg)
{
        int id = *(int *) arg;
        int tmp;
        while(1) {
                /* Entry section (Student programming for random time) */
                sleep(rand() % 5 + 1);
                printf("Student #%d is going to TA room.\n", id);
                fflush(stdout);

                /* Check for available chairs and take action (Critical section) */
                pthread_mutex_lock(&mutex_chairs);
                tmp = used_chairs;
                pthread_mutex_unlock(&mutex_chairs);

                /* CASE 1: There's enough space. */
                if (tmp < 3) {
                        if (tmp == 0) {
                                /* Empty chairs. TA may be sleeping: Try to wake him up. */
                                waking_student = id;
                                sem_post(&sem_ta_sleep);
                        }

                        /* Takes seat */
                        pthread_mutex_lock(&mutex_chairs);
                        tmp = (c + used_chairs) % 3; /* Where he is sitting next */
                        used_chairs++;
                        printf("Student #%d sat on chair #%d. %d chair(s) remain.\n",id,tmp+1,3 - used_chairs);
                        fflush(stdout);
                        pthread_mutex_unlock(&mutex_chairs);

                        /* Waits for TA to call the student. */
                        sem_wait(&sem_chairs[tmp]);
                        printf("TA is teaching student #%d.\n", id);

                        /* Waits for time with TA to finish */
                        sem_wait(&sem_std);
                        printf("TA finished teaching student #%d.\n", id);
                        fflush(stdout);
                        printf("Student #%d left TA room.\n", id);
                        fflush(stdout);

                        return NULL;
                } else {
                        /* CASE 2: Not enough space. Student will come back later. */
                        printf("There is no available chair to student %d. The student will return late.\n", id);
                }
        }
}


int main(int argc, char const *argv[])
{
        int n = atoi(argv[1]); /* Starting number of students */
        active_students = n;

        pthread_t ta;          /* TA task id */
	pthread_t stds_tid[n]; /* Student task ids */
        int stds_num[n];       /* Student numbers/names (ids) */


        sem_init(&sem_ta_sleep, 0, 0);
        sem_init(&sem_std, 0, 0);
        for (int i = 0; i<3; i++) {
                sem_init(&sem_chairs[i], 0, 0);
        }
        pthread_mutex_init(&mutex_chairs, NULL);
        pthread_mutex_init(&mutex_stds, NULL);

        /* Run tasks */
        srand(time(NULL));
        pthread_create(&ta,NULL,ta_task,NULL);
        for (int i = 1; i<=n; i++) {
                stds_num[i] = i;
                pthread_create(&stds_tid[i],NULL,student_task,(void *) &stds_num[i]);
        }

        /* Wait for tasks to finish */
        pthread_join(ta, NULL);
        for (int i = 1; i<=n; i++) {
                pthread_join(stds_tid[i], NULL);
        }
        printf("TA went back to sleep.\n");
        printf("There is no more students to help. TA left the room.\n");
        fflush(stdout);

        /* Memory cleanup */
        pthread_mutex_destroy(&mutex_chairs);
        pthread_mutex_destroy(&mutex_stds);
        sem_destroy(&sem_ta_sleep);
        for (int i = 0; i < 3; i++) {
                sem_destroy(&sem_chairs[i]);
        }

        return 0;
}