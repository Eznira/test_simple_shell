#include "main.h"

/**
 * _printf - Custom implementation of printf function.
 * @str: The format string.
 * @arg_list: A va_list of arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *str, ...)
{
	int count_char = 0;
	va_list arg_list;
	int i;
	int is_placeholder = 0;
	
	va_start(arg_list, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;

			for (i = 0; i < placeholder_map_size; i++)
			{
				if (*str == placeholder_map[i].placeholder_id)
				{
					count_char += placeholder_map[i].
						print_type(arg_list);
					is_placeholder = 1;
					break;
				}
			}

			if (!is_placeholder)
			{
				_putchar('%');
				count_char++;
			}
		}
		else
		{
			_putchar(*str);
			count_char++;
		}

		str++;
	}

	return (count_char);
}
