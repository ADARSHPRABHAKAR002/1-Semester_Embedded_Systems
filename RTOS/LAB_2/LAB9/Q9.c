/*Write a program which forks a new process. Let the child process compute the
summation of first n natural numbers, and let it output the result. Pass ‘n’ as a
commandline argument. The parent waits for the child to complete and finally
the parent process too outputs the result.
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        // Compute the summation of first 'n' natural numbers
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i;
        }
        // Output the result from the child process
        printf("Child Process: Sum of first %d natural numbers = %d\n", n, sum);
        exit(sum); // Exit with the sum as the status
    } else { // Parent process
        int childStatus;
        // Wait for the child process to complete
        wait(&childStatus);
        // Extract and output the result from the child's exit status
        int sum = WEXITSTATUS(childStatus);
        printf("Parent Process: Sum of first %d natural numbers = %d\n", n, sum);
    }

    return 0;
}

