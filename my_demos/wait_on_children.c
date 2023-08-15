#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int i;
    pid_t child_pid;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            // Child process
            printf("Child %d executing ls -l /tmp:\n", i + 1);
            execlp("ls", "ls", "-l", "/tmp", (char *)NULL);
            perror("Exec failed");
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process
            waitpid(child_pid, NULL, 0); // Wait for the child to exit
        }
    }

    return 0;
}
