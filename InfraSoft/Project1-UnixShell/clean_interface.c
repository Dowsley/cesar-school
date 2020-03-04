#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <sys/wait.h>
#include <string.h>

#define MAX_LINE 80  // Tamanho máximo de comando

void getInput(char buffer[MAX_LINE]);
int parseInput(char* args[MAX_LINE/2+1], char buffer[MAX_LINE]);

int main()
{
	//pid_t pid;
	
	char* args[MAX_LINE/2+1];
	char buffer[MAX_LINE];
	char history[MAX_LINE];
	int argsize;
	
	getInput(buffer);  		   // Gets and inserts into the buffer.
	argsize = parseInput(args,buffer); // Parses input and gets back the args size.
	
	// Updates history
	if (!strcmp(args[0],"!!"))
	{
		strcpy(history,buffer);
	}

	/*while(1)
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
		
		
	}*/
    
	return 0;
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