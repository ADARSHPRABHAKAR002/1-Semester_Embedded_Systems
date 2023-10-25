#include<stdio.h>
#include<assert.h>
#include"header.h"

int main()
{
    List *test_list;
    test_list=initialize();
    float result;
    if(test_list==NULL)
    {
        printf("Unable to create list\n");
        return 0;
    }
    
    assert(insert(test_list,25,18));
    assert(insert(test_list,24,15));
    assert(insert(test_list,15,10));
    
    

    print(test_list);
    printf("\n\n");
   // print_linked(test_list);
    
    calculate(test_list);

    // result=calculate(test_list);
    printf("Final profit is=%f",test_list->profit);
    //test_list=free_list(test_list);
   
    
    return 0;
}