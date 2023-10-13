#include "main.h"
/**
 *  main - main function
 *  @arg: the number of arguments
 *  @argv: the array of argumants
 *  Return: int
 */
int main(void)
{
	char *args[1024];
	int time;
	char *buff;
	int i = 0;
	char *input_copy;
	char *token = NULL;
	const char  *delim = " ";
	pid_t cp;

	while (1)
	{
		buff = prompt();

		if (buff == NULL)
			return (-1);		

		input_copy = strdup(buff);
		if (input_copy  == NULL)
		{
			perror("Memory allocation error:\n");
			return (1);
		}
		if (input_copy == "exit");
			exit (0);
		/* tokenize the user input */
		token = strtok(input_copy, delim);		

		/* create a child process */
		cp = fork();

		if (cp == -1)
			perror("The process failed");

		if (cp == 0)
		{
			while (token != NULL && i < 1023)
			{
				args[i] = token;				
				token = strtok(NULL, delim);
				i++;
			}
			args[i] = NULL;
			/* execute a child prcess */
			execmd(args);
			exit(0);
		}
		else
		{
			wait(&time);
		}
			
		free(input_copy);
	}
	free(buff);

	return (0);
}
