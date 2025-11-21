#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything based on a format string
 * @format: Types of arguments (e.g., "cisf")
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int pos = 0;
	char *sepa = "", *str;

	va_start(args, format);

	while (format && format[pos])
	{
		switch (format[pos])
		{
			case 'c':
				printf("%s%c", sepa, va_arg(args, int));
				sepa = ", ";
				break;
			case 'i':
				printf("%s%d", sepa, va_arg(args, int));
				sepa = ", ";
				break;
			case 'f':
				printf("%s%f", sepa, va_arg(args, double));
				sepa = ", ";
				break;
			case 's':
				str = va_arg(args, char *);
				if (!str)
					str = "(nil)";
				printf("%s%s", sepa, str);
				sepa = ", ";
				break;
			default:
				break;
		}
		pos++;
	}
	va_end(args);
	printf("\n");
}
