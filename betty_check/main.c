#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	int i;
	size_t input_size = 0;
	char *input = NULL, *args[MAX_INPUT_SIZE], *command = NULL;

	while (1)
	{
		printf("$ ");
		get_input(&input, &input_size);

		/* Check for end of file (Ctrl+D) */
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		if (strlen(input) == 0)
		{
			continue;
		}

		/* Tokenize input into command and arguments */
		tokenize_input(input, &command, args);

		/* Find and execute the built-in command */
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
			pid_t child_pid = fork();

			if (child_pid < 0)
			{
				perror("Fork failed");
			}
			else if (child_pid == 0)
			{
				execvp(args[0], args);
				perror("Execvp failed");
				exit(1);
			}
			else
			{
				waitpid(child_pid, NULL, 0);
			}
		}
	}

	free(input);
	free(command);

	return (0);
}
