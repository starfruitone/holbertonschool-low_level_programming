#include "main.h"
/**
 * _isgit - Checks for 0 to 9
 * @c: checks char
 *
 * returns 1 if c is a digit, if not then a 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	    return (1);
	return (0);
}
