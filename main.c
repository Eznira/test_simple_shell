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

		// Print parsed command and arguments
		printf("Command: %s\n", command);
		for (int i = 0; args[i] != NULL; ++i)
		{
			printf("Arg %d: %s\n", i, args[i]);
		}

	}

	free(input);
	free(command);

	return 0;
}
