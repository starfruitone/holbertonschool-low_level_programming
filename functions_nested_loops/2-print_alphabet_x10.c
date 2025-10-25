#include "main.h"

/**
*print_alphabet_x10- ecrire l'alphabet en 10 fois
*Return: Always 0 (Success)
*/
void print_alphabet_x10(void)
{

	char c;
	char e;

	for (c = '0'; c <= '9'; c++)
	{
		for (e = 'a'; e <= 'z'; e++)
		{
		_putchar(e);
		}
	_putchar('\n');
	}
}
