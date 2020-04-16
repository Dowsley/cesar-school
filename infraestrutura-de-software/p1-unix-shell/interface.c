#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

#define MAX_LINE 80  // Maximum length

int findSymbol(char* args[MAX_LINE/2+1], char* ch);  // Finds and returns position by (STRCMP)
int isParallel(char* str);            // Checks if there is the "&" keyword
void getInput(char buffer[MAX_LINE]); // Gets user input from keyboard and stores into the buffer;
int parseInput(char* args[MAX_LINE/2+1], char buffer[MAX_LINE]); // Transforms command into readable args

int main()
{
	pid_t pid;
	pid_t ppid;

	char* args[MAX_LINE/2+1]; // Standard input format for shell command execution
	char buffer[MAX_LINE];    // Temporary buffer to store user input
	char history[MAX_LINE];   // Temporary place to hold the last used command
	int argsize; 		  // Args size 
    	int fd;      		  // File descriptor
    	int pos;		  // Temporary position holder  
	int pfd[2];		  // Pipe file descriptor
	
	history[0] = '\0';
	while(1)
	{
		printf("osh>");
		fflush(stdout);

		getInput(buffer);
		if (!strcmp(buffer,"exit")) break;
		if (strcmp(buffer,"!!")) strcpy(history,buffer); // updates history buffer, unless it's "!!"

		pid = fork();

		if (pid < 0) // Error
		{
			printf("ERROR: Could not fork");
			exit(0);
		}

		else if (pid > 0) // Parent
		{
			if (!(isParallel(buffer))) wait(NULL);  // Only goes parallel if "&" flag was detected inside inputs  
		}

		else if (pid == 0) // Child
		{	
			if (strcmp(buffer,"!!")) // Normal execution
			{
				argsize = parseInput(args,buffer);
			}
			else // Last command (history)
			{
				if (history[0] == '\0')
				{
					printf("No commands in history.\n");
					fflush(stdout);
				}
				else
				{
					strcpy(buffer,history);
					argsize = parseInput(args,buffer); // Parses last used command into args. 
					for (int i = 0; args[i] != NULL; i++)
					{
						printf("%s ",args[i]);
						fflush(stdout);
					}
					printf("\n");
					fflush(stdout);
				}
			}
            
            		// '&' Removal
			if (!strcmp(args[argsize-1], "&"))
			{
				args[argsize-1] = NULL;
			}

			// Redirect check
			if ( (pos = findSymbol(args, ">")) >= 0 ) // Console to file
			{
				fd = open(args[pos+1], O_CREAT | O_WRONLY);
				dup2(fd, STDOUT_FILENO);   
				close(fd);

				args[pos] = NULL;
			}
			else if ( (pos = findSymbol(args,"<")) >= 0 ) // File to console
			{
				fd = open(args[pos+1], O_RDONLY);
				dup2(fd, STDIN_FILENO);    
				close(fd);

				args[pos] = NULL;
			}

			// Pipe call check
			else if ((pos = findSymbol(args,"|")) >= 0)
			{	
				// Creating pipes
				if (pipe(pfd) == -1)
				{
					printf("Error: pipe failed");
					fflush(stdout);
					exit(1);
				}

				ppid = fork();
				
				if (ppid < 0)  // Error
				{
					printf("Error creating child");
					fflush(stdout);
				}
				// EXAMPLE: ls | sort
				else if (ppid > 0) // Parent (sort)
				{
					dup2(pfd[0],STDIN_FILENO); // Reads input to use as args to SORT
					close(pfd[1]);

					// Rewrite command
					for (int i = pos+1, j = 0; ; i++, j++)
					{
						if (args[i] == NULL)
						{
							args[j] = NULL;
							break;
						}
						else
						{
							args[j] = malloc(strlen(args[i])+1 * sizeof(char));
							for (int x = 0; ; x++)
							{
								args[j][x] = args[i][x];
								if (args[i][x] == '\0')
									break;
							}
						}
					}

					wait(NULL);
				}
				else if (ppid == 0) // Child (ls)
				{
					dup2(pfd[1],STDOUT_FILENO); // Writes output os LS command
					close(pfd[0]); 
						
					// Rewrite command
					args[pos] = NULL;
				}
			}

			execvp(args[0],args); // Sends everything to unix shell
			exit(0);
		}
	}
    
	return 0;
}

// Return its position
int findSymbol(char* args[MAX_LINE/2+1], char* ch)
{
    for (int i = 0; args[i] != NULL; i++)
    {
        if (!strcmp(args[i], ch))
        {
            return i;
        }
    }
    return -1;
}



// Tells if the command is asking for parallelization
int isParallel(char* str)
{
	for (int i = 0; ; i++)
	{
		if (str[i] == '\0'){
			if (str[i-1] == '&') return 1;
			else return 0;
		}
	}
}

// Gets input from the keyboard and stores into the buffer
void getInput(char buffer[MAX_LINE])
{
	// Gets input
	fflush(stdin);
	fgets(buffer,MAX_LINE,stdin);
	for (int i = 0; ; i++)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			break;
		}
	}
}

// Splits the input and inserts into the args. Returns the ARGS size.
int parseInput(char* args[MAX_LINE/2+1], char buffer[MAX_LINE])
{
	int size;
	int pos = 0;
	char tempBuffer[MAX_LINE];
	strcpy(tempBuffer,buffer);
	
	char* pc = strtok(tempBuffer, " ");
	while (pc != NULL)
	{
		// Size count
		size = 0;
		for (int i = 0; ; i++)
		{
			size++;
			if (pc[i] == '\0')
			{
				break;
			}
		}
		args[pos] = malloc(size * sizeof(char));
		strcpy(args[pos], pc);
		pc = strtok(NULL, " ");
		pos++;
	}
	args[pos] = NULL;
	return pos;
}