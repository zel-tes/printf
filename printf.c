#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - it prints
 * @format: format string
 *
 * Return: Always 0
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *ptr;
	char *stval, *str;
	int cval;

	va_start(ap, format);

	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr != '%')
			write(1, ptr, 1);
		continue;
		switch (*++ptr)
		{
			case 'c':
				cval = va_arg(ap, int);
				str = malloc(2 * sizeof(char));
				if (str == NULL)
					exit(1);
				str[0] = cval;
				str[1] = '\0';
				write(1, str, 1);
				free(str);
				break;
			case 's':
				stval = va_arg(ap, char *);
				str = malloc((strlen(stval) + 1) * sizeof(char));
				if (str == NULL)
					exit(1);
				strcpy(str, stval);
				write(1, str, strlen(str));
				free(str);
				break;
			default:
				write(1, ptr, 1);
				break;
		}
	}
	va_end(ap);
	return (0);
}
