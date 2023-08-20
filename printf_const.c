#include "main.h"

const placeholder_struct_t placeholder_map[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{'d', print_int},
	{'i', print_int},
	{'b', print_bin},
	{'u', print_unsigned_decimal},
	{'o', print_octal},
	{'x', _print_lower_hex},
	{'X', _print_upper_hex},
	{'S', print_str_cus},
	{'p', print_p},
};

const int placeholder_map_size = sizeof(placeholder_map)
	/ sizeof(placeholder_map[0]);
