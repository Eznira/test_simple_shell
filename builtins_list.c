#include "shell.h"

/* Built-in commands list */
const BuiltInCommand builtins[] = {
    {"cd", builtin_cd},
//    {"pwd", builtin_pwd},
//    {"echo", builtin_echo},
    /* Add more built-in commands here */
};

/* Number of bultins */
const int num_builtins = sizeof(builtins) / sizeof(builtins[0]);
