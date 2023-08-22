#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "builtins.h"
#include "printf.h"

#define MAX_INPUT_SIZE 1024

/**
 * struct BuiltInCommand - Represents a built-in command.
 * @name: The name of the command.
 * @handler: Pointer to the function that handles the command.
 */
typedef struct {
    const char *name;
    void (*handler)(char **args);
} BuiltInCommand;

/* Contstants */
extern const BuiltInCommand builtins[];
extern const int num_builtins;

/* Util functions */
ssize_t _getline(char **line_input_ptr, size_t *n, FILE *stream);
int _printf(const char *str, ...);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, char *delim);

/* Shell functions */
void get_input(char **input, size_t *input_size);
void tokenize_input(char *input, char **command, char **args);

/* Builtins */
void builtin_cd(char **args);
void builtin_env(char **args);
void builtin_exit(char **args);
void builtin_setenv(char **args);
void builtin_unsetenv(char **args);

#endif /* SHELL_H */
