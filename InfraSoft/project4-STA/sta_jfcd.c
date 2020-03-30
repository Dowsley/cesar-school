#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *run_thread(void *arg);

int main(int argc, char const *argv[])
{
        int n = atoi(argv[1]);
        int threads[n];
        for (int i = 0; i<n; i++) {
                threads[n] = n;
        }

        return 0;
}

void *run_thread(void *arg)
{

}