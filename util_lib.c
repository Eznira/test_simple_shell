#include "shell.h"

/**
 * _getline - Read a line from a file stream.
 * @line_input_ptr: Pointer to the buffer that will store the input line.
 * @n: Pointer to the size of the buffer.
 * @stream: The file stream to read from.
 *
 * This function reads a line from the provided file stream and stores it in
 * a dynamically allocated buffer. The buffer size is increased as needed to
 * accommodate the entire line.
 *
 * Return: The number of characters read, excluding the null-terminator.
 *         -1 if an error occurs.
 */
ssize_t _getline(char **line_input_ptr, size_t *n, FILE *stream) {
    int buff_size = 64;
    int index = 0;
    char *buffer = (char *)malloc(buff_size * sizeof(char));

    if (!buffer) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    int c;
    while (1) {
        c = fgetc(stream);

        if (c == EOF) {
            buffer[index] = '\0';
            break;
        } else if (c == '\n') {
            buffer[index] = c;
            index++;
            buffer[index] = '\0';
            break;
        } else {
            buffer[index] = c;
        }

        index++;

        if (index >= buff_size) {
            buff_size += 64;
            buffer = (char *)realloc(buffer, buff_size * sizeof(char));

            if (!buffer) {
                perror("Memory reallocation error");
                exit(EXIT_FAILURE);
            }
        }
    }

    *line_input_ptr = buffer;
    *n = buff_size;
    return (ssize_t)index;
}

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return:
 *   0 if the strings are equal
 *   a negative value if s1 is less than s2
 *   a positive value if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (s1[i] - s2[i]);
}
