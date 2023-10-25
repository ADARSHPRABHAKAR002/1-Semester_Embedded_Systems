#ifndef _HASH_H_
#define _HASH_H_
#define NAME_LENGTH 50
#define HASHTABLE_SIZE 26
#define FAILURE 0
#define SUCCESS 1

typedef struct hash_node
{
    char name[NAME_LENGTH];
    char detail[100];
    struct hash_node *ptr;
    
}H_node;

typedef struct hash_list
{
    H_node *head;
    H_node *tail;
    int count;
    
}H_list;

typedef struct hash_table
{
    H_list arr[HASHTABLE_SIZE];
}H_table;
int insert(char [],char []);
int get_key(char);


#endif