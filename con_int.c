#include "main.h"
/**
 * con_int - function converts int leger to string
 * @n: index
 * Return: void
 */
void con_int(int n)
{
	if (n > 9)
		con_int(n / 10);
	_putchar(n % 10 + '0');
}
