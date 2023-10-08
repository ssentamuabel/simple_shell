#include<unistd.h>
/**
 *  _putchar - print a character to the stdout
 *  @c: the character to be printed
 *
 *  Return: 1 for success and -1 for failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
