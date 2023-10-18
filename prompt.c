#include "main.h"
/**
 * prompt- function that generates a prompt
 * Return: void
 */
char *prompt(void)
{
	char *display = "(sashell)$ ";
	char *buff = NULL;
	size_t size;
	ssize_t result;

	_puts(display);
	result = getline(&buff, &size, stdin);
		if (result == -1)
	{
		perror("Exit");
		return (NULL);
	}
	if (buff[result - 1] == '\n')
		buff[result - 1] = '\0';
	return (buff);
}
