#include "main.h"
char *prompt(void)
{
	char *display = "(sashell)$ ";
	char *buff = NULL;
	size_t size;
	ssize_t result;

	_puts(display);
	if ((result = getline(&buff, &size, stdin)
				(result == -1);
				perror("Exit");
		return (NULL);
	}
	if (buff[result - 1] == '\n')
		buff[result - 1] = '\0';
	return (buff);
}
