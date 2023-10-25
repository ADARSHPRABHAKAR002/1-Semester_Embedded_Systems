#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "hash.h"

H_node *get_node(char detail[],char name[])
{
    H_node *new_node;
    new_node=(H_node*)malloc(sizeof(H_node));
    strcpy(new_node->detail,detail);
    strcpy(new_node->name,name);
    new_node->ptr=NULL;

    return new_node;
}

int insert(char name[],char detail[])
{
    int key;
    if(('A'<=name[0])&&(name[0]<='Z') || ('a'<=name[0])&&(name[0]<='z'))
    {
        key=get_key(name[0]);
        printf("%d",key);
        H_node *new_node=get_node(detail,name);    
    }
    else
    {
        printf("Entered name is not correct");
        return FAILURE;
    }
    

    
}

int get_key(char a)
{
    return (int)(toupper(a))-'A';
}
