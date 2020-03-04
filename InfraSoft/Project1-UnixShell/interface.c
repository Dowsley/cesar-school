#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LINE 80  // Tamanho máximo de comando

void printCommand(char* com[MAX_LINE/2+1])
{
    for (int i = 0; com[i] != NULL; i++){
        printf("%s", com[i]);
    }
    fflush(stdout);
}

// Retorna 1 se o último comando for &, 0 se não for.
int getAndParseInput(char* args[MAX_LINE/2+1], char* history_buffer[MAX_LINE/2+1])
{
    char buffer_in[MAX_LINE];  // Stores the raw input
    char buffer_out[MAX_LINE]; // Stores temporary parsed commands
    int param_pos = 0;         // Parameters position in the array (starts at args[0])

    // Gets user input
    fflush(stdin);
    fgets(buffer_in, MAX_LINE, stdin);

    // PARSE INPUT CASE 1: !!
    if (buffer_in[0] == '!' && buffer_in[1] == '!' && buffer_in[3] == '\0')
    {
        args[0] = malloc(3 * sizeof(char));
        strcpy(args[0], "!!");
        return 0;
    }
    
    // PARSE INPUT CASE 2: Other command
    else
    {
        for (int i = 0, j = 0;; i++, j++)
        {
            buffer_out[j] = buffer_in[i];

            // Parse keywords (case 1: Space between commands)
            if (buffer_in[i] == ' '){
                buffer_out[j] = '\0';
                args[param_pos] = malloc((i+1) * sizeof(char));
                strcpy(args[param_pos], buffer_out);
                history_buffer[param_pos] = malloc((i+1) * sizeof(char));
                strcpy(history_buffer[param_pos], buffer_out);
                param_pos++;  // Jumps to next param slot
                j = -1;
            }

            // Parse keywords (case 2: End of Stream)
            else if (buffer_in[i] == '\n'){
                buffer_out[j] = '\0';
                args[param_pos] = malloc((i+1) * sizeof(char));
                strcpy(args[param_pos], buffer_out);
                history_buffer[param_pos] = malloc((i+1) * sizeof(char));
                strcpy(history_buffer[param_pos], buffer_out);
                param_pos++;
                args[param_pos] = NULL; // Last parameter must be Null
                history_buffer[param_pos] = NULL; // Last parameter must be Null

                if (args[param_pos-1][0] == '&'){
                    args[param_pos] = NULL;
                    history_buffer[param_pos] = NULL;
                    
                    return (param_pos-1); // Retorna posição do &
                }
                else{
                    return 0;  // Não existe &
                }
            }
        }
    }
}

int main(void)
{
    char* args[MAX_LINE/2+1];   // command line arguments
    char* history_buffer[MAX_LINE/2+1];
    int parallel;
    pid_t pid;

    history_buffer[0] = NULL;
    while(1)
    {
        printf("osh>");
        fflush(stdout);

        parallel = getAndParseInput(args, history_buffer);
        if (!strcmp("exit", args[0])){
            break;
        }

        pid = fork();
        if (pid < 0)    // Aborted child
        {
            printf("<< ERROR: Child creation unsuccessfull >>");
            fflush(stdout);
            exit(0);
        }

        else if (pid > 0)   // Pai: Espera entrada
        {   
            if (!parallel){
                wait(NULL);
            }
        }

        else if (pid == 0)   // Filho: Executa comando
        {
            if (args[0][0] == '!' && args[0][1] == '!')
            {
                if (history_buffer[0] == NULL){
                    printf("<< ERROR: No previous command used >>\n");
					fflush(stdout);
                    exit(0);
                }
                else{
                    printCommand(history_buffer);
                    if (parallel)
                        history_buffer[parallel] = NULL;
                    execvp(history_buffer[0],history_buffer);
                }
            }
            else
            {
                if (parallel)
                    args[parallel] = NULL;
                execvp(args[0], args);
            }
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
