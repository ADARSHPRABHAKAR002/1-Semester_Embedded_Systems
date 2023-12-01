/*To demonstrate the usage of the various shared memory system 
calls- WAP which creates a shared memory segment of length 100 bytes
and writes 'A' to 'Z' to it. 
Next, let the same program access the segment area and display its 
contents to the screen (all 100 bytes).Let the program next convert 
the case of the alphabets in the segment to lowercase. Finally let 
the program access the same area and display the segment contents 
once again to the screen. Observe the output.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>

int main() {
    key_t key = ftok("shared_memory_key", 65); // Generate a key for the shared memory segment
    int i=0;
    // Create a shared memory segment of length 100 bytes
    int shmid = shmget(key, 100, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the program's address space
    char *shared_memory = (char *)shmat(shmid, NULL, 0);

    // Write 'A' to 'Z' to the shared memory segment
    for (int i=0; i<10;i++) {
        shared_memory[i] = i;
    }
    for(i,char c='A';c<='Z';i++,c++)
        {
                shared_memory[i]=c;
        }

    // Display the contents of the shared memory segment before case conversion
    printf("Contents of shared memory before case conversion: %s\n", shared_memory);

    // Convert the characters in the shared memory segment to lowercase
    for (int i = 0; i < 26; ++i) {
        shared_memory[i] = tolower(shared_memory[i]);
    }

    // Display the contents of the shared memory segment after case conversion
    printf("Contents of shared memory after case conversion: %s\n", shared_memory);

    // Detach the shared memory segment from the program's address space
    shmdt(shared_memory);

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

