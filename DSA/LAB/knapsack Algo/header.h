#ifndef _HEADER_H_
#define _HEADER_H_
#define SUCCESS 1
#define FAILURE 0
#define MAX1 20

typedef struct _node_
{
    float pi;
    float wi;
    float ratio;
    struct _node_ *ptr;
    
}Node;

typedef struct _list_
{
    Node *header;
    Node *tail;
    float max;
    float profit;
    int count;
}List;

List *initialize();
Node *getnode(float,float);
int insert(List *,float , float);
void print(List *);
List* free_list(List *);
void calculate(List *);

void print_linked(List *);


#endif