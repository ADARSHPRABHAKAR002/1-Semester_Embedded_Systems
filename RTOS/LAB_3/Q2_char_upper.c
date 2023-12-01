/*Let a parent process create a segment of adequate length and 
write 0 to 9 as well as 'a' to 'z' to it.Next, let the parent fork a 
child.Let the child increment all the integers by a value 100. Also 
let it convert all the characters to upper case. Once the child 
completes, let the parent access the shared area and display their 
contents to the screen.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <ctype.h>

int main() {
    key_t key = ftok("shared_memory_key", 65); // Generate a key for the shared memory segment
    int i=0;
    // Create a shared memory segment of adequate length (assuming 36 bytes for 0 to 9 and a to z)
    int shmid = shmget(key, 36, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the program's address space
    char *shared_memory = (char *)shmat(shmid, NULL, 0);

    // Write integers 0 to 9 and characters 'a' to 'z' to the shared memory segment
    for (int i = 0; i < 10; ++i) {
        shared_memory[i] = i + '0'; // Store integers 0 to 9
    }

    for (int i = 0; i < 26; ++i) {
        shared_memory[i + 10] = 'a' + i; // Store characters 'a' to 'z'
    }

    // Fork a child process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) { // Child process
        // Increment integers by 100
        for (int i = 0; i < 10; ++i) {
            shared_memory[i] += 100;
        }

        // Convert characters to uppercase
        for (int i = 0; i < 26; ++i) {
            shared_memory[i + 10] = toupper(shared_memory[i + 10]);
        }

        // Detach the shared memory segment from the child's address space
        shmdt(shared_memory);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        // Wait for the child process to complete
        wait(NULL);

        // Display the contents of the shared memory segment after the child process completes
        printf("Contents of shared memory after child process:\n");
        for (int i = 0; i < 36; ++i) {
            printf("%c ", shared_memory[i]);
        }
        printf("\n");

        // Detach the shared memory segment from the parent's address space
        shmdt(shared_memory);

        // Remove the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}

