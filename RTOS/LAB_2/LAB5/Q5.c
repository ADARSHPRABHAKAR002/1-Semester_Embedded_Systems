/*Spawn (create) a child process which executes ls command
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        // Execute ls command in the child process
        char *args[] = {"ls", NULL};
        execvp(args[0], args);

        // If execvp fails, print an error message and exit
        perror("execvp");
        exit(EXIT_FAILURE);
    } else { // Parent process
        // Wait for the child process to complete
        wait(NULL);
        printf("Child process has completed.\n");
    }

    return 0;
}

