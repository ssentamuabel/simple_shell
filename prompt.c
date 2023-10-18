#include "main.h"
/**
 * prompt- function that creates a continous prompt
 * Return: vod
 */
char *prompt(void)
{
	char *display = "(SAshell)$ ";
	char *buff = NULL;
	size_t size;
	ssize_t result;

	_puts(display);
	if ((result = getline(&buff, &size, stdin))== -1)
	{
		perror("Exit");
		return (NULL);
	}
	if (buff[result - 1] == '\n')
		buff[result - 1] = '\0';
	return (buff);
}



