#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - performs simple operations
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, various on failure
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	func = get_op_func(argv[2]);
	if (func == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	if ((argv[2][0] == '/' || argv[2][0] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = func(num1, num2);
	printf("%d\n", result);

	return (0);
}
