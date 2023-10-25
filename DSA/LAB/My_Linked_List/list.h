#define SUCCESS 1
#define FAILURE 0

typedef struct _node_
{
    struct _node_ *ptr;
    int data;
}Node;

typedef struct _list_
{
    Node *head;
    Node *tail;
    int count; 
}List;

List *initialise();

int insert_at_beg(List *,int);
void display(List *);
int insert_at_end(List *,int);
//int insert_after_data(List *,int);