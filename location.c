#include "main.h"
char *get_location(char *command)
{
	char *path, *path_copy, *file_path, *path_token;
	int command_length = 0;
	int path_length = 0;
	struct stat buff;

	path = getenv("PATH");

	if (path)
	{
		/* create a dupicate of path */
		path_copy = strdup(path);

		command_length = strlen(command);

		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			path_length = strlen(path_token);
			file_path = malloc(path_length + command_length + 2);
			if (file_path == NULL)
				return (NULL);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buff)== 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
			
				path_token = strtok(NULL, ":");
			}
			
		}
		free(path_copy);
		
		/* Check  if the command itself existed */
		if (stat(command, &buff) == 0)
			return (command);

		return (NULL);

	}
	return (NULL);
}
