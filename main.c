#include "shell.h"

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;

	char *command = NULL;
	char *args[MAX_INPUT_SIZE];

	while (1)
	{
		printf("$ ");  // Display prompt
		read_input(&input, &input_size);  // Read user input

		// Parse input into command and arguments
		parse_input(input, &command, args);

                // Create a child process
		pid_t child_pid = fork();

		if (child_pid < 0) {
			perror("Fork failed");
		} else if (child_pid == 0) {
               // Child process: execute the command
			execvp(args[0], args);
			perror("Execvp failed");
			exit(1);
		} else  {
               // Parent process: wait for the child to complete
			waitpid(child_pid, NULL, 0);
		}

	free(input);
	free(command);

	return 0;
	}
}
