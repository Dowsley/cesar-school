#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LINE 80  // Tamanho máximo de comando

// Retorna 1 se o último comando for &, 0 se não for.
int getAndParseInput(char* args[MAX_LINE/2+1])
{
    char buffer_in[MAX_LINE];  // Stores the raw input
    char buffer_out[MAX_LINE]; // Stores temporary parsed commands
    int param_pos = 0;         // Parameters position in the array (starts at args[0])

    // Gets user input
    fflush(stdin);
    fgets(buffer_in, MAX_LINE, stdin);

    // Parse input
    for (int i = 0, j = 0;; i++, j++)
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

            if (args[param_pos-1][0] == '&'){
                args[param_pos-1] = NULL;
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

/*void updateHistoryBuffer(char* args[MAX_LINE/2+1], char* history_buffer[MAX_LINE/2+1])
{
    // "cat a.txt &\0"
    int size;
    for (int i = 0; ; i++){
        size = sizeof(args[i])/sizeof(char);
        printf("\n[[%d]] = ", size);
        history_buffer[i] = malloc(sizeof(char) * size);
        strcpy(history_buffer[i], args[i]);
        printf("{{%s -> %s}}", args[i], history_buffer[i]);
    }
}*/

int main(void)
{
    char* args[MAX_LINE/2+1];   // command line arguments
    //char* history_buffer[MAX_LINE/2+1];
    int isParallel;
    pid_t pid;

    while(1)
    {
        printf("osh>");
        fflush(stdout);

        isParallel = getAndParseInput(args);
        //updateHistoryBuffer(args,history_buffer);

        if (!strcmp("exit", args[0])){
            break;
        }

        pid = fork();

        if (pid < 0){
            printf("<< ERROR: Child creation unsuccessfull >>");
            exit(0);
        }

        else if (pid > 0){   // Pai: Espera entrada
            if (!isParallel){
                wait(NULL);
            }
        }

        else if (pid == 0){  // Filho: Executa comando
            execvp(args[0], args);
        }

        /*
        * After reading user input, the steps are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        * (3) parent will invoke wait() unless command included &
        */
    }

    return 0;
}
