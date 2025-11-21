#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints values based on format string
 * @format: Format string, where each char indicates argument type
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *str, *sep = "";

	va_start(ap, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			printf("%s%c", sep, va_arg(ap, int));
		}
		else if (format[i] == 'i')
		{
			printf("%s%d", sep, va_arg(ap, int));
		}
		else if (format[i] == 'f')
		{
			printf("%s%f", sep, va_arg(ap, double));
		}
		else if (format[i] == 's')
		{
			str = va_arg(ap, char *);
			if (!str)
				str = "(nil)";
			printf("%s%s", sep, str);
		}
		if (format[i] == 'c' || format[i] == 'i' ||
		    format[i] == 'f' || format[i] == 's')
			sep = ", ";
		i++;
	}
	va_end(ap);
	printf("\n");
}
