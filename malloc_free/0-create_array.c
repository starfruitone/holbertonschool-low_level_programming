#include <stdlib.h>

/**
 * create_array - Creates an array of chars, initializes with a specific char
 * @size: Size of the array
 * @c: Char to initialize with
 *
 * Return: Pointer to array, or NULL if size is 0 or fails
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
		return (NULL);

	arr = malloc(size * sizeof(char));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = c;

	return (arr);
}
