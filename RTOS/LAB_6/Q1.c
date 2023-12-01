/*1. 
(Readers-Writers problem; to do simple implementation using pthreads, and mutex locks for the CS region)
Create two threads. 
Thread1 is a reader which reads a sample text file and transfers all the words in the file to a new file.
Thread 2 is a writer which appends a user provided message  to the same file, n times to the files end
Use mutex locks to ensure synchronisation among the two threads. 
Run your program and observe the result on each run.
Also remove the locks and observe the result.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define FILENAME "sample.txt"
#define OUTPUT_FILENAME "output.txt"
#define MESSAGE "User-provided message."

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
FILE *file;

void *reader_thread(void *arg) {
    char word[100];
    FILE *input_file = fopen(FILENAME, "r");

    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(input_file, "%s", word) != EOF) {
        pthread_mutex_lock(&mutex);
        fprintf(file, "%s ", word);
        pthread_mutex_unlock(&mutex);
    }

    fclose(input_file);
    pthread_exit(NULL);
}

void *writer_thread(void *arg) {
    int i, n = *((int *)arg);

    for (i = 0; i < n; i++) {
        pthread_mutex_lock(&mutex);
        fprintf(file, "%s\n", MESSAGE);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    file = fopen(OUTPUT_FILENAME, "w");

    if (file == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    pthread_t reader, writer;
    int write_iterations = 5; // Number of times the writer thread appends the message

    pthread_create(&reader, NULL, reader_thread, NULL);
    pthread_create(&writer, NULL, writer_thread, &write_iterations);

    pthread_join(reader, NULL);
    pthread_join(writer, NULL);

    fclose(file);

    return 0;
}
