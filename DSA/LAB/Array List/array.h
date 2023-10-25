#ifndef ARRAY_STATIC
#define ARRAY_STATIC


#define MAX_SIZE 20
#define FOUND 1
#define NOT_FOUND 0

struct _array_
{
    int array[MAX_SIZE];
    int c_size, t_size;
};

typedef struct _array_ Array;

Array intialize_array(int);
Array insert_data(Array, int);
int search(Array, int);


#endif
