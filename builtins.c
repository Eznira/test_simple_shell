/* Contains all built-in functions*/

#include "shell.h"

/**
 * builtin_cd - Change the current directory.
 * @args: Array of command arguments.
 */
void builtin_cd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr, "cd: missing argument\n");
        return;
    }

    if (chdir(args[1]) != 0) {
        perror("cd");
    }
}

/**
 * builtin_env - Display the current environment variables.
 */
void builtin_env(char **args)
{
    extern char **environ; // Declare the external environment variable array

    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}

/**
 * builtin_exit - Exit the shell.
 * @args: Array of arguments passed to the exit command.
 *
 * If no argument is provided, the shell will exit with status 0.
 * If an integer argument is provided, the shell will exit with that status.
 * If the provided argument is not a valid integer, an error message will be printed.
 */
void builtin_exit(char **args)
{
    if (args[1] != NULL) {
        char *endptr;
        int exit_status = (int)strtol(args[1], &endptr, 10);
	
        if (*endptr != '\0') {
            fprintf(stderr, "exit: Invalid argument: %s\n", args[1]);
            return;
        }

        exit(exit_status);
    } else {
        exit(0);
    }
}
