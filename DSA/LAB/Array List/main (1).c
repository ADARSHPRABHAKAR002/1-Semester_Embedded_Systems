#include<assert.h>
#include "array.h"

int main()
{
    Array test_arr;

    //initialize array
    test_arr = intialize_array(10);
    assert(test_arr.c_size == 0 && test_arr.t_size == 10);

    //insert data in a array

    test_arr = insert_data(test_arr, 10);
    test_arr = insert_data(test_arr, 20);
    test_arr = insert_data(test_arr, 30);
    test_arr = insert_data(test_arr, 40);
    test_arr = insert_data(test_arr, 50);
    test_arr = insert_data(test_arr, 60);
    test_arr = insert_data(test_arr, 70);
    test_arr = insert_data(test_arr, 80);
    test_arr = insert_data(test_arr, 90);
    test_arr = insert_data(test_arr, 100);

    assert(test_arr.c_size == 10);
    assert(test_arr.array[9] == 100);

    //array full
    test_arr = insert_data(test_arr, 55);
    assert(test_arr.c_size == 10);

    assert(search(test_arr, 100));
    assert(search(test_arr, 70));
    assert(search(test_arr, 50));
    assert(search(test_arr, 55) == 0);

    return 0;
}
