#include "main.h"
/**
 *  _puts - prints the string to console
 *  @str: the address of the string
 *
 *  Return: int
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}
