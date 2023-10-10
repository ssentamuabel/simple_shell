#include "main.h"
void execmd(char **args)
{
	char *command = NULL;
	char *envp[] = {NULL};
	char *path_command;

	if (args)
	{
		command = args[0];
		path_command = get_location(command);

		if (execve(path_command, args, envp) == -1)
		{
			perror("Error: ");
		}
	}
}
