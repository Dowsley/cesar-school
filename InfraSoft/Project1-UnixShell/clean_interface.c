#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LINE 80  // Tamanho máximo de comando

int parseInputs(char* args[MAX_LINE/2+1], char buffer[500]);

int main()
{
	pid_t pid;
	
	char* args[MAX_LINE/2+1];
	char history[MAX_LINE];
	int size;
	
	// Gets input
	char buffer[100];
	fflush(stdin);
	fgets(buffer,MAX_LINE,stdin);

	for (int i = 0; ; i++)
	{
		if (buffer[i] == '\n'){
			buffer[i] = '\0';
			break;
		}
	}
	
	// Parses input
	size = parseInputs(args,buffer);
	
	while(1)
	{
		pid = fork();

		if (pid < 0) // Erro
		{

		}

		else if (pid > 0) // Pai
		{
			wait(NULL);
		}

		else if (pid == 0) // Filho
		{
			
		}
		
		
	}
    
	return 0;
}

int parseInputs(char* args[MAX_LINE/2+1], char buffer[500])
{
	int size;
	int pos = 0;
	char* pc = strtok(buffer, " ");

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