#include "main.h"
int main(void)
{
	char *buff = NULL; 
	char *input_copy = NULL;
	char *token = NULL;
	char *path_location = NULL;
	char *args[1204];
	const char *delim = " ";
	int i;
	int time = 0;
	pid_t cp;


	while (1)
	{
		buff = prompt();
		
		if (buff == NULL)
			return (-1);

		input_copy = strdup(buff);

		if (input_copy == NULL)
		{
			perror("Memory allocation error");
			return (-1);
		}
		if (strcmp(input_copy, "exit") == 0)
			exit(0);
		/* tokenize the user input */
		token = strtok(input_copy, delim);
		i = 0;
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, delim);
			i++;
			
		}
		args[i] = NULL;
		/* get the full path */
		path_location = get_location(args[0]);
		if (path_location == NULL)
			perror("");	
		args[0] = path_location;	
		/* create a child process */
		cp = fork();

		if (cp == -1)
			perror("The process failed ");
		if (cp == 0)
		{
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
