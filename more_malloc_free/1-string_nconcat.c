#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings, using at most n bytes from s2
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to use
 *
 * Return: pointer to new space in memory, NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *cat;

	if (s1)
		while (s1[len1])
			len1++;
	if (s2)
		while (s2[len2])
			len2++;

	if (n > len2)
		n = len2;

	cat = malloc((len1 + n + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		cat[i] = s1 ? s1[i] : '\0';
	for (j = 0; j < n; j++)
		cat[i + j] = s2 ? s2[j] : '\0';
	cat[i + j] = '\0';

	return (cat);
}
