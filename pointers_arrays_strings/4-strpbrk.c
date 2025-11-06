#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: String to search
 * @accept: Bytes to search for
 *
 * Return: Pointer to the byte in s that matches one of accept, or NULL if not found
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
				return (s);
		}
		s++;
	}
	return (0);
}
