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

    while(should_run)
    {
        printf("osh>");
        fflush(stdout);

        // Get user input.
        fflush(stdin);
        fgets(buffer_in, MAX_LINE, stdin);
        printf("Raw input: %s", buffer_in);

        // Parse input.
        for (int i = 0, j = 0; i==i; i++, j++)
        {
            // Parse keywords
            buffer_out[j] = buffer_in[i];
            if (buffer_in[i] == ' '){
                buffer_out[j] = '\0';
                args[param_pos] = malloc((i+1) * sizeof(char));
                strcpy(args[param_pos], buffer_out);
                param_pos++;  // Jumps to next param slot
                j = -1;
            }

            else if (buffer_in[i] == '\0'){
                args[param_pos] = malloc((i+1) * sizeof(char));
                strcpy(args[param_pos], buffer_out);
                break;
            }

        }

        printf("Command: %s", args[0]);
        for (int i = 1; i<=param_pos; i++){
            printf("\nParameter %d: %s", i, args[i]);
        }

        should_run = 0;
        /**
        * After reading user input, the steps are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        * (3) parent will invoke wait() unless command included &
        */
    }

    return 0;
}
