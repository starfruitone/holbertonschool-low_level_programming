#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a new string which is a duplicate of str
 * @str: The string to duplicate
 *
 * Return: Pointer to duplicated string, or NULL if str is NULL or insufficient memory
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}
