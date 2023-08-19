/* builtins.c */

#include "shell.h"

/* Define the array of built-in commands */
const BuiltInCommand builtins[] = {
    {"cd", builtin_cd},
    {"pwd", builtin_pwd},
    {"echo", builtin_echo},
    /* Add more built-in commands here */
};

/* Numbersb of bultins */
const int num_builtins = sizeof(builtins) / sizeof(builtins[0]);
