#include "shell.h"

void read_input(char **input, size_t *input_size)
{
    getline(input, input_size, stdin);
    (*input)[strlen(*input) - 1] = '\0';
}

void parse_input(char *input, char **command, char **args)
{
    *command = strtok(input, " ");
    int arg_count = 0;
    args[arg_count++] = *command;

    char *arg = strtok(NULL, " ");
    while (arg != NULL)
    {
        args[arg_count++] = arg;
        arg = strtok(NULL, " ");
    }
    args[arg_count] = NULL;
}
