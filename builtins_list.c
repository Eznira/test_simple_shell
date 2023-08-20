#include "shell.h"

/* Built-in commands list */
const BuiltInCommand builtins[] = {
    {"cd", builtin_cd},
    {"env", builtin_env},
    {"exit", builtin_exit},
};

/* Number of bultins */
const int num_builtins = sizeof(builtins) / sizeof(builtins[0]);
