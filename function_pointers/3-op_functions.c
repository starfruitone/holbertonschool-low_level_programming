#include "3-calc.h"

/**
 * op_add - Adds two values
 * @a: first input
 * @b: second input
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subtracts second value from first
 * @a: minuend
 * @b: subtrahend
 * Return: result of a - b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiplies two numbers
 * @a: first input
 * @b: second input
 * Return: product
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Divides first value by second
 * @a: dividend
 * @b: divisor
 * Return: quotient
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - Gets remainder of division
 * @a: number
 * @b: divisor
 * Return: remainder
 */
int op_mod(int a, int b)
{
	return (a % b);
}
