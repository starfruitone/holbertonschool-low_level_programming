#include "main.h"

/**
 * prime_helper - checks recursively if n is divisible by i
 * @n: number to check
 * @i: divisor
 * Return: 1 if prime, 0 otherwise
 */
int prime_helper(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0)
		return (0);
	return (prime_helper(n, i - 1));
}

/**
 * is_prime_number - checks if integer is a prime number
 * @n: number to check
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_helper(n, n - 1));
}
