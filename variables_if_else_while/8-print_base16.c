#include<stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
	char c;
	char b;

	for (c = '0'; c <= '9'; c++)
	{
	putchar(c);
	}
	for (b = 97; b <= 102; b++)
	{
	putchar(b);
	}
	putchar('\n');
	return (0);
}
