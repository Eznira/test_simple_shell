#include "shell.h"

int main(void)
{
    char *input = NULL;
    size_t input_size = 0;

    char *command = NULL;
    char *args[MAX_INPUT_SIZE];
    int is_background = 0;

    const char *exit_shell = "exit";

    while (1)
    {
        /* Display prompt */
        printf("$ ");
        get_input(&input, &input_size);

        /* Check for end of file (Ctrl+D) */
        if ((feof(stdin)) | (strcmp(exit_shell, input) == 0))
        {
            printf("\n");
            break;
        }

        /* Check for background execution */
        is_background = 0;
        if (input[strlen(input) - 1] == '&')
        {
            is_background = 1;
            input[strlen(input) - 1] = '\0';
        }

        /* Tokenize input into command and arguments */
        tokenize_input(input, &command, args);

        /* Find and execute the built-in command */
        int i;
        for (i = 0; i < num_builtins; i++)
        {
            if (strcmp(command, builtins[i].name) == 0)
            {
                builtins[i].handler(args);
                break;
            }
        }

        if (i == num_builtins)
        {
	       	/* Create a child process */
		pid_t child_pid = fork();

		if (child_pid < 0)
		{
			perror("Fork failed");
		}
		else if (child_pid == 0)
		{
			/* Child process: execute the command */
			execvp(args[0], args);
			perror("Execvp failed");
			exit(1);
		}
		else
		{
			if (!is_background)
			{
				/* Parent process: wait for the child to complete */
				waitpid(child_pid, NULL, 0);
			}
		}
        }


    }

    free(input);
    free(command);

	return (0);

}
