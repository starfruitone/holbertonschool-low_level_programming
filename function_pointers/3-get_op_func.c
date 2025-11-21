#include "3-calc.h"
#include <stdlib.h>

/**
 * get_op_func - Finds correct operation for the given operator string
 * @s: Operator from user input
 * Return: Pointer to math function or NULL on failure
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (s && *s == *ops[i].op && !*(s + 1))
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
