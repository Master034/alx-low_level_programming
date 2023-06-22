#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
  *print_all - prints anything.
  *@format: list of all arguments passed to the function.
  *
  *Return: void.
  */
void print_all(const char * const format, ...)
{
	unsigned int i;
	va_list args;
	char *s, *separator;

	va_start(args, format);

	separator = "";

	i = 0;
	while (format && format[i])
	{
		if (format[i] == 'c')
			printf("%s%c", separator,  va_arg(args, int));
		else if (format[i] == 'i')
			printf("%s%d", separator, va_arg(args, int));
		else if (format[i] == 'f')
			printf("%s%f", separator, va_arg(args, double));
		else if (format[i] == 's')
		{
			s = va_arg(args, char *);
			if (s == NULL)
				s = "(nil)";
			printf("%s%s", separator, s);
		}
		separator = ", ";
		i++;
	}

	printf("\n");
	va_end(args);
}
