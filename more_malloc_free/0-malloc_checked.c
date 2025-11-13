#include <stdlib.h>

/**
 * malloc_checked - Allocates memory use malloc, exits with status 98 on fail
 * @b: Number of bytes to allocate
 *
 * Return: Pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
		exit(98);
	return (p);
}
