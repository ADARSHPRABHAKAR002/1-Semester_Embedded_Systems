/*Spawn a child which executes copy command cp (Note: the copy command
takes 2 arguments meant for source filename and destination file name.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        // Execute cp command with source and destination file names in the child process
        char *args[] = {"cp", "source.txt", "destination.txt", NULL}; // Change source.txt and destination.txt accordingly
        execvp(args[0], args);

        // If execvp fails, print an error message and exit
        perror("execvp");
        exit(EXIT_FAILURE);
    } else { // Parent process
        // Wait for the child process to complete
        wait(NULL);
        printf("Copy operation completed.\n");
    }

    return 0;
}

