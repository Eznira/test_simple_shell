#include <unistd.h>
#include <stdarg.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int print_char(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);
	return 1;
}

int print_string(va_list args)
{
	char *s = va_arg(args, char*);
	int count = 0;

	while (*s)
	{
		_putchar(*s);
		s++;
		count++;
	}
	return count;
}

int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return 1;
}

int _print_int_helper(int n)
{
	int count = 0;
	if (n / 10)
		count += _print_int_helper(n / 10);

	_putchar('0' + n % 10);
	count++;

	return count;
}

int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}

	if (n / 10)
		count += _print_int_helper(n / 10);

	_putchar('0' + n % 10);
	count++;

	return count;
}

int print_bin(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    int binary[32];
    int i = 0;

    while (num > 0)
    {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    if (i == 0)
    {
        _putchar('0');
        count++;
    }
    else
    {
        while (i > 0)
        {
            _putchar('0' + binary[i - 1]);
            count++;
            i--;
        }
    }

    return count;
}

int _print_un_deci_helper(unsigned int num)
{
    int count = 0;
    if (num / 10)
        count += _print_un_deci_helper(num / 10);

    _putchar('0' + num % 10);
    count++;

    return count;
}

int print_unsigned_decimal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;

    if (num == 0)
    {
        _putchar('0');
        count++;
    }
    else
    {
        if (num / 10)
            count += _print_un_deci_helper(num / 10);

        _putchar('0' + num % 10);
        count++;
    }

    return count;
}

int print_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    int octal[32];
    int i = 0;

    while (num > 0)
    {
        octal[i] = num % 8;
        num /= 8;
        i++;
    }

    if (i == 0)
    {
        _putchar('0');
        count++;
    }
    else
    {
        while (i > 0)
        {
            _putchar('0' + octal[i - 1]);
            count++;
            i--;
        }
    }

    return count;
}

int _print_lower_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    char hex_chars[] = "0123456789abcdef";
    char hex[32];
    int i = 0;

    while (num > 0)
    {
        hex[i] = hex_chars[num % 16];
        num /= 16;
        i++;
    }

    if (i == 0)
    {
        _putchar('0');
        count++;
    }
    else
    {
        while (i > 0)
        {
            _putchar(hex[i - 1]);
            count++;
            i--;
        }
    }

    return count;
}

int _print_upper_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0;
    char hex_chars[] = "0123456789ABCDEF";
    char hex[32];
    int i = 0;

    while (num > 0)
    {
        hex[i] = hex_chars[num % 16];
        num /= 16;
        i++;
    }

    if (i == 0)
    {
        _putchar('0');
        count++;
    }
    else
    {
        while (i > 0)
        {
            _putchar(hex[i - 1]);
            count++;
            i--;
        }
    }

    return count;
}

int print_str_cus(va_list args)
{
	char *s = va_arg(args, char*);
	int count = 0;

	while (*s)
	{
		if (*s < 32 || *s >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar((*s / 16) < 10 ? '0' + (*s / 16) : 'A' + (*s / 16) - 10);
			_putchar((*s % 16) < 10 ? '0' + (*s % 16) : 'A' + (*s % 16) - 10);
			count += 4;
		}
		else
		{
			_putchar(*s);
			count++;
		}
		s++;
	}

	return (count);
}

/**
 * print_p - Print a pointer address in hexadecimal format.
 */
int print_p(va_list args)
{
	void* ptr = va_arg(args, void*);
	unsigned long int addr = (unsigned long int)ptr;
	int count = 0;
	char hex_chars[] = "0123456789abcdef";
	char hex[16];
	int i = 0;

	/* Convert the address to hexadecimal */
	while (addr > 0)
	{
		hex[i] = hex_chars[addr % 16];
		addr /= 16;
		i++;
	}

	/* Print the pointer address in hexadecimal */
	_putchar('0');
	_putchar('x');
	count += 2;

	if (i == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (i > 0)
		{
			_putchar(hex[i - 1]);
			count++;
			i--;
		}
	}

	return (count);
}
