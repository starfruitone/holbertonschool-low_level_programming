#include "main.h"

/**
* print_sign- elle ecris les signes
* @n: permet de cherche les chiffres
* Return: Always 0 (Success)
*/

int print_sign(int n)
{
	if (n < 0)
	{
		_putchar('-');
		return (-1);
	}

	if (n > 0)
	{
		_putchar('+');
		return (1);
	}

	else
	{
		_putchar('0');
		return (0);
	}
}
