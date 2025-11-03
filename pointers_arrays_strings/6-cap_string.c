#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to modify
 *
 * Return: Pointer to the resulting string
 */
char *cap_string(char *str)
{
	int i = 0, j;
	char seps[] = " \t\n,;.!?\"(){}";

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - ('a' - 'A');

	while (str[i] != '\0')
	{
		for (j = 0; seps[j] != '\0'; j++)
		{
			if (str[i] == seps[j])
			{
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
					str[i + 1] = str[i + 1] - ('a' - 'A');
			}
		}
		i++;
	}

	return (str);
}
