#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct placeholder_struct - Holds a placeholder character and
 *                             the respective print function pointer.
 * @placeholder_id: The placeholder character.
 * @print_type:     The corresponding print function.
 */
typedef struct placeholder_struct
{
	char placeholder_id;
	int (*print_type)(va_list);
} placeholder_struct_t;

extern const placeholder_struct_t placeholder_map[];
extern const int placeholder_map_size;

int _putchar(char c);
int _printf(const char *str, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int _print_int_helper(int n);
int print_bin(va_list args);
int _print_un_deci_helper(unsigned int num);
int print_unsigned_decimal(va_list args);
int print_octal(va_list args);
int _print_lower_hex(va_list args);
int _print_upper_hex(va_list args);
int print_str_cus(va_list args);
int print_p(va_list args);

#endif /* MAIN_H */
