<<<<<<< HEAD
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
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        printf("MyShell> ");
        fflush(stdout);

        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            break;
        }

        // Remove the trailing newline character
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        // Parse the input using strtok
        char *token = strtok(input, " ");
        char *args[MAX_INPUT_LENGTH]; // Array to hold command and arguments
        int i = 0;

        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }

        args[i] = NULL; // Set the last element to NULL for execvp

        pid_t child_pid = fork(); // Create a child process

        if (child_pid < 0) {
            perror("Fork failed");
        } else if (child_pid == 0) {
            // Child process: execute the command
            execvp(args[0], args);
            perror("Execvp failed");
            exit(1);
        } else if (input == "exit") {
              break;
        } else  {
            // Parent process: wait for the child to complete
            waitpid(child_pid, NULL, 0);
        } 
    }

    return 0;
>>>>>>> d99a9da (local test)
}
