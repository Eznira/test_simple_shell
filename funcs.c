#include "shell.h"

/**
 * get_input - Reads input from stdin and removes newline character
 * @input: Pointer to store the input string
 * @input_size: Pointer to the size of the input string
 *
 * This function reads a line of input from stdin and removes the trailing
 * newline character. It uses getline to dynamically allocate memory for the
 * input string.
 */
void get_input(char **input, size_t *input_size)
{
	_getline(input, input_size, stdin);
	(*input)[strlen(*input) - 1] = '\0';
}

/**
 * tokenize_input - Tokenizes input string into command and arguments
 * @input: Input string to be tokenized
 * @command: Pointer to store the command token
 * @args: Array of pointers to store the argument tokens
 *
 * This function tokenizes the input string based on spaces and stores the
 * command token in the 'command' pointer and argument tokens in the 'args'
 * array of pointers. It uses strtok to perform the tokenization.
 */
void tokenize_input(char *input, char **command, char **args)
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
