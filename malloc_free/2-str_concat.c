#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Pointer to new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;
	char *cat;

	if (s1 != NULL)
		while (s1[len1])
			len1++;
	if (s2 != NULL)
		while (s2[len2])
			len2++;

	cat = malloc((len1 + len2 + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		cat[i] = s1 ? s1[i] : '\0';
	for (j = 0; j < len2; j++)
		cat[i + j] = s2 ? s2[j] : '\0';
	cat[i + j] = '\0';

	return (cat);
}
