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
