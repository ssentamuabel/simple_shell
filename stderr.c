#include "main.h"
/**
 * std_er - function that prints to standard error
 * @r: parameter
 * Return: 1
 */
int std_er(char *r)
{
	int i = 0;

	while (r[i])
	{
		write(STDERR_FILENO, &r[i], 1);
		i++;
	}
	return (1);
}
