#include "main.h"

/**
* _islower- Je sais pas 'a' ce qu'elle fais merci
* @c: Je crois que c'est bon la description
* Return: Always 0 (Success)
*/

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}
