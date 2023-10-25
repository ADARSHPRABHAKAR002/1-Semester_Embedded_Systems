/*Fork 3 children . One of them executes ls, another date and the third pwd
command. Run the program and observe the results on each run.*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int i;
    pid_t pid;

    for (i = 0; i < 3; ++i) {
        pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Child processes
            if (i == 0) {
                // First child executes ls command
                execlp("ls", "ls", NULL);
            } else if (i == 1) {
                // Second child executes date command
                execlp("date", "date", NULL);
            } else {
                // Third child executes pwd command
                execlp("pwd", "pwd", NULL);
            }

            // If execlp fails, print an error message and exit
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }

    // Parent process waits for all children to complete
    for (i = 0; i < 3; ++i) {
        wait(NULL);
    }

    return 0;
}

