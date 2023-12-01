/*(First Readers-Writers problem; using pthreads, and mutex locks for the CS region)
Create five threads of which three are reader threads and two are writer threads. Each of the reader threads reads all the words of a common sample text file and writes the same to a new file (you can name the output files as one.txt, two.txt, and three.txt respectively from the from three reader threads ). One of the writer threads appends "Hello world" message 10 times to the sample file, while the other writer appends "Hello everyone" message 25 times to the same sample file.  
Ensure synchronisation by implementing your solution based on the "First-readers-writers problem". 
Run your code as many times as possible and observe the results.
Also remove the locks and observe the result.*/



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define FILENAME "sample.txt"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wrt = PTHREAD_MUTEX_INITIALIZER;

int readcount = 0;

void start_read() {
    pthread_mutex_lock(&mutex);
    readcount++;
    if (readcount == 1) {
        pthread_mutex_lock(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}

void end_read() {
    pthread_mutex_lock(&mutex);
    readcount--;
    if (readcount == 0) {
        pthread_mutex_unlock(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}

void *reader_thread(void *arg) {
    char word[100];
    char *output_filename = (char *)arg;

    FILE *input_file = fopen(FILENAME, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    start_read();

    while (fscanf(input_file, "%s", word) != EOF) {
        fprintf(output_file, "%s ", word);
    }

    end_read();

    fclose(input_file);
    fclose(output_file);
    pthread_exit(NULL);
}

void *writer_thread(void *arg) {
    int i, n = *((int *)arg);

    pthread_mutex_lock(&wrt);

    for (i = 0; i < n; i++) {
        FILE *file = fopen(FILENAME, "a");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        if (i % 2 == 0) {
            fprintf(file, "Hello world\n");
        } else {
            fprintf(file, "Hello everyone\n");
        }
        fclose(file);
    }

    pthread_mutex_unlock(&wrt);
    pthread_exit(NULL);
}

int main() {
    pthread_t readers[3], writers[2];
    char *output_files[3] = {"one.txt", "two.txt", "three.txt"};
    int write_iterations1 = 10; // Hello world message
    int write_iterations2 = 25; // Hello everyone message

    for (int i = 0; i < 3; i++) {
        pthread_create(&readers[i], NULL, reader_thread, output_files[i]);
    }

    pthread_create(&writers[0], NULL, writer_thread, &write_iterations1);
    pthread_create(&writers[1], NULL, writer_thread, &write_iterations2);

    for (int i = 0; i < 3; i++) {
        pthread_join(readers[i], NULL);
    }

    pthread_join(writers[0], NULL);
    pthread_join(writers[1], NULL);

    return 0;
}
