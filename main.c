#include "main.h"

/**
 *  main - main function
 *  @arg: the number of arguments
 *  @argv: the array of argumants
 *  Return: int
 */
int main(int arg, char **argv)
{
	char *prompt = "(sashell)$ ", *buff = NULL;
	size_t size;
	char *args[1024], *envp[] = {NULL};
	int time, i = 0;
	ssize_t length = 0;
	char *input_copy, *token = NULL;
	const char  *delim = " ";
	pid_t cp;
	


	while (1)
	{
		_puts(prompt);
		length = getline(&buff, &size, stdin);
		if (length == -1)
		{
			perror("Exit sashell....\n");
			return (-1);
		}

		if (buff[length - 1] == '\n')
			buff[length - 1] = '\0';


		

		input_copy = strdup(buff);
		if (input_copy  == NULL)
		{
			perror("Memory allocation error:\n");
			exit(1);
		}
		
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
				args[i] = token; // Store each  token as an argument
				
				token = strtok(NULL, delim);
				i++;
			}
			args[i] = NULL;
			/* execute a child prcess */
			if (execve(args[0], args, envp) == -1)
			{
				perror("Error: ");
				exit(1);
			}
			exit(0);
		}
		else
		{
			wait(&time);
			_puts("This is a parent process ");
			_putchar('\n');
		}
	
		

		free(input_copy);
	}


	free(buff);

	return (0);
}
