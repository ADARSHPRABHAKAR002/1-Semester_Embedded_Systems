#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "list.h"

int main()
{   
    List *test_list;

    test_list = initialise_list();
    assert(test_list->head == NULL && test_list->tail == NULL);
    assert(test_list->count == 0);

    assert(insert_at_beg(test_list, 10));
    assert(test_list->head == test_list->tail);

    
    assert(test_list->count == 1);

    assert(insert_at_beg(test_list, 20));
    assert(insert_at_beg(test_list, 30));
    assert(insert_at_beg(test_list, 40));
    assert(insert_at_beg(test_list, 50));
    assert(insert_at_beg(test_list, 60));

    assert(test_list->count == 6);
    assert(test_list->head->data == 60);
    assert(test_list->tail->data == 10);
    assert(test_list->head->ptr->ptr->ptr->ptr->data == 20);

    assert(search_list(test_list, 10));
    assert(search_list(test_list, 20));
    assert(search_list(test_list, 30));
    assert(search_list(test_list, 40));
    assert(search_list(test_list, 50));
    assert(search_list(test_list, 60));

    assert(search_list(test_list, 70) == 0);

    assert(insert_at_end(test_list, 70));
    assert(insert_at_end(test_list, 80));
    assert(insert_at_end(test_list, 90));

    assert(test_list->count == 9);
    assert(test_list->tail->data == 90);

    assert(insert_after_data(test_list, 100, 90));
    assert(test_list->tail->data == 100);

    assert(insert_after_data(test_list, 100, 90));

    assert(insert_after_data(test_list, 110, 50));
    assert(test_list->head->ptr->ptr->data == 110);
    assert(search_list(test_list,110) == 1);
    assert(test_list->count ==12);

    assert(delete_at_beg(test_list));
    assert(delete_at_beg(test_list));
    assert(delete_at_beg(test_list));

    assert(test_list->head->data == 40);
    assert(test_list->count == 9);
    return 0;
}
