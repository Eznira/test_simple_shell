#ifndef BUILTINS_H
#define BUILTINS_H

#include <unistd.h>

void builtin_cd(char **args);
void builtin_env(char **args);
void builtin_exit(char **args);

#endif /* BUILTINS_H */
