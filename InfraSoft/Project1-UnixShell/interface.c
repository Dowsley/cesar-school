#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
    char* args[MAX_LINE/2 + 1]; /* command line arguments */
    int should_run = 1;         /* flag to determine when to exit program */

    char buffer_in[MAX_LINE];  // Stores the raw input
    char buffer_out[MAX_LINE]; // Stores temporary parsed commands
    int param_pos = 0;         // Parameters position in the array (starts at args[0])

    pid_t pid;
    while(should_run)
    {
        printf("osh>");
        fflush(stdout);

        // Gets user input
        fflush(stdin);
        fgets(buffer_in, MAX_LINE, stdin);

        // Parse input
        for (int i = 0, j = 0; i==i; i++, j++)
        {
            buffer_out[j] = buffer_in[i];

            // Parse keywords (case 1: Space between commands)
            if (buffer_in[i] == ' '){
                buffer_out[j] = '\0';
                args[param_pos] = malloc((i+1) * sizeof(char));
                strcpy(args[param_pos], buffer_out);
                param_pos++;  // Jumps to next param slot
                j = -1;
            }

            // Parse keywords (case 2: End of Stream)
            else if (buffer_in[i] == '\n'){
                buffer_out[j] = '\0';
                args[param_pos] = malloc((i+1) * sizeof(char));
                strcpy(args[param_pos], buffer_out);
                param_pos++;
                args[param_pos] = NULL; // Last parameter must be Null
                break;
            }
        }

        /*printf("Command: %s", args[0]);
        for (int i = 1; i<=param_pos; i++){
            printf("\nParameter %d: %s", i, args[i]);
        }*/

        if (!strcmp("exit", args[0]))
        {
            should_run = 0;
        }

        else
        {
            execvp(args[0], args);
        }

        /**
        * After reading user input, the steps are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        * (3) parent will invoke wait() unless command included &
        */
    }

    return 0;
}
