#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LINE 80  // Tamanho máximo de comando

int isParallel(char* str);
void getInput(char buffer[MAX_LINE]);
int parseInput(char* args[MAX_LINE/2+1], char buffer[MAX_LINE]);

int main()
{
	pid_t pid;
	
	char* args[MAX_LINE/2+1];
	char buffer[MAX_LINE];
	char history[MAX_LINE];
	int argsize;

	history[0] = '\0';
	while(1)
	{
		printf("osh>");
		fflush(stdout);

		getInput(buffer);
		if (!strcmp(buffer,"exit")) break;
		if (strcmp(buffer,"!!")) strcpy(history,buffer);

		pid = fork();

		if (pid < 0) // Error
		{
			printf("ERROR: Could not fork");
			exit(0);
		}

		else if (pid > 0) // Parent
		{
			if (!(isParallel(buffer))) wait(NULL);
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
					printf("ERROR: No previous command\n");
				}
				else
				{
					strcpy(buffer,history);
					argsize = parseInput(args,buffer); // Executes history 
				}
			}
			
			if (!strcmp(args[argsize-1], "&"))
			{
				args[argsize-1] = NULL; // Remove & keyword
			}
			execvp(args[0],args);
		}
	}
    
	return 0;
}

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