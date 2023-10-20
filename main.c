#include "main.h"
int main(int num, char **argv, char *envp[]);
/**
 * main- main function
 * @argv: arguments
 * @num: number
 * @envp: environment variable
 * Return: 0 (Success)
 */
int main(int num, char **argv, char *envp[])
{
	char *buff = NULL, *input_copy = NULL;
	char *token = NULL;
	char *path_location = NULL;
	char *args[1204];
	const char *delim = " ";
	int i, status = 0;
	int time = 0, dec = 0;
	pid_t cp;

	(void)num;
	(void)argv;


	while (1)
	{
		dec++;
		buff = prompt();
		if (buff == NULL)
			return (-1);
		if (strcmp(buff, "env") == 0)
		{
			i = 0;
			for (i = 0; envp[i] != NULL; i++)
			{
				_puts(envp[i]);
				_puts("\n");
			}
			status = 0;
			continue;
		}
		if (strcmp(buff, "exit") == 0)
		{
			exit(status);
			exit(0);
		}
		input_copy = strdup(buff);
		if (input_copy == NULL)
		{
			perror("Memory allocation error");
			return (-1);
		}
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
		free(buff);
		/* get the full path */
		path_location = get_location(args[0]);
		if (path_location == NULL)
		{
			std_er(argv[0]);
			std_er(": ");
			con_int(dec);
			std_er(": ");
			std_er(args[0]);
			std_er(": not found\n");
			status = 127;
			continue;
		}
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

	return (0);
}
