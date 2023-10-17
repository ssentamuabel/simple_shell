#include "main.h"
char *prompt (void)
{
	char *display = "(sashell)$ ";
	char *input = NULL;
	size_t size;
	ssize_t result;

	_puts(display);
	if ((result = getline(&input, &size, stdin)) == -1)
	{
		perror("Exit");
		return (NULL);
	}
	if (input[result - 1] =='\n')
		input[result - 1] = '\0';
	
	return (input);
}
