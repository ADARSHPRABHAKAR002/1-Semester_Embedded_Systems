#include<stdlib.h>
#include"list.h"
#include<stdio.h>
#include<assert.h>

int main()
{

    List *test_list;

    test_list=initialise();
    assert(test_list->head==NULL && test_list->tail==NULL);
    assert(test_list->count==0);

    assert(insert_at_beg(test_list,10));
    assert(insert_at_beg(test_list,20));
    assert(insert_at_beg(test_list,30));
   // display(test_list);
    assert(insert_at_end(test_list,40));
    assert(insert_at_end(test_list,50));
    display(test_list);
    return 0;
    
}