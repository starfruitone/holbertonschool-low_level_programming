#include "main.h"

/**
 * sqrt_helper - Recursively finds the square root
 * @n: Number
 * @i: Candidate square root
 * Return: Natural sqrt, or -1
 */
int sqrt_helper(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - Returns natural square root of a number
 * @n: Number
 * Return: Sqrt or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 0));
}

