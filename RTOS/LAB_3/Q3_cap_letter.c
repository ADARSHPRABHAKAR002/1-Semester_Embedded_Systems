/*Let a parent process create a segment of length 2k and write n 
strings to the area. Let the value of n be passed as a commandline 
argument. Next, let the parent fork a child.Let the child capitalise 
the first character of each string.Once the child completes let the 
parent access the shared area and display their contents to the 
screen.*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_strings>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]); // Number of strings
    int k = 256; // Length of the shared memory segment (assuming maximum length of each string is 256 characters)

    key_t key = ftok("shared_memory_key", 65); // Generate a key for the shared memory segment

    // Create a shared memory segment of length 2k
    int shmid = shmget(key, 2 * k, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the program's address space
    char *shared_memory = (char *)shmat(shmid, NULL, 0);

    // Ask the user to enter n strings and write them to the shared memory segment
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; ++i) {
        fgets(shared_memory + i * k, k, stdin);
    }

    // Fork a child process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) { // Child process
        // Capitalize the first character of each string
        for (int i = 0; i < n; ++i) {
            shared_memory[i * k] = toupper(shared_memory[i * k]);
        }

        // Detach the shared memory segment from the child's address space
        shmdt(shared_memory);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        // Wait for the child process to complete
        wait(NULL);

        // Display the contents of the shared memory segment after the child process completes
        printf("Contents of shared memory after child process:\n");
        for (int i = 0; i < n; ++i) {
            printf("%s", shared_memory + i * k);
        }

        // Detach the shared memory segment from the parent's address space
        shmdt(shared_memory);

        // Remove the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}


