#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/* Function declarations */
void get_input(char **input, size_t *input_size);
void tokenize_input(char *input, char **command, char **args);

#endif /* SHELL_H */
