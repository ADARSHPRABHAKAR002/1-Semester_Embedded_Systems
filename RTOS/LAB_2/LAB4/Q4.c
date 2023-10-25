/*Create a child process which outputs your name to the screen and exits with a
value 255. Use wait() system call in the parent, for the child to complete 
execution. Also use
the WEXITSTATUS macro to display the status value returned by the child.*/


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
        printf("Child process: My name is ChatGPT!\n");
        exit(255); // Exit with value 255
    } else { // Parent process
        int status;
        wait(&status); // Wait for the child process to complete

        if (WIFEXITED(status)) {
            printf("Parent process: Child exited with status: %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent process: Child process did not exit normally.\n");
        }
    }

    return 0;
}

