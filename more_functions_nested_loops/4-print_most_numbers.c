#include "main.h"

/**
 * print_most_numbers - Prints numbers 0 to 9 except 2 and 4, followed by newline
 *
 * Return: void
 */
void print_most_numbers(void)
{
	char str[] = "01356789\n";
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
