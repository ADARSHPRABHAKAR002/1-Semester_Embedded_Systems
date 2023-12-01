#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<assert.h>
int main()
{
    H_table *Table;
    Table=get_table();
    assert(insert(Table,"Adarsh"));
    assert(insert(Table,"Abhi"));
    assert(insert(Table,"Zubia"));
    assert(insert(Table,"Sudeep"));
    assert(insert(Table,"Puneeth"));
    assert(insert(Table,"Shiv"));
    
    assert(insert(Table,"Dha"));
    assert(insert(Table,"Darshan"));
    assert(insert(Table,"Dhanush"));
    assert(insert(Table,"Sagar"));
    assert(insert(Table,"Ashish"));
    print(Table);

    search(Table,"Dhanush");

    deallocate(Table);

    return 0;
}