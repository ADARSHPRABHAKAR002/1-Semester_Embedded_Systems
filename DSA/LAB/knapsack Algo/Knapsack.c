#include<stdio.h>
#include <stdlib.h>
#include "header.h"

List *initialize()
{
    List *new;
    new=(List*)malloc(sizeof(List));
    new->header=NULL;
    new->tail=NULL;
    new->count=0;
    new->max=MAX1;
    new->profit=0;
    return new;
}

Node *getnode(float pi, float wi)
{
    Node *n_node;
    n_node=(Node*)malloc(sizeof(Node));
    n_node->pi=pi;
    n_node->wi=wi;
    n_node->ratio=pi/wi;
    n_node->ptr=NULL;
    return n_node;
}

int insert(List *list,float pi, float wi)
{
    Node *new_node;
    new_node=getnode(pi,wi);
    if(list->count==0)
    {
        list->header=new_node;
        list->tail=new_node;
        list->count++;
        return SUCCESS;
    }
    else if(new_node->ratio<=list->tail->ratio)
    {
        list->tail->ptr=new_node;
        list->tail=new_node;
        list->count++;
        return SUCCESS;
    }
    else if(new_node->ratio>=list->header->ratio)
    {
        new_node->ptr=list->header;
        list->header=new_node;
        list->count++;
        return SUCCESS;
    }
    else
    {
        
        Node *temp,*prev;
        temp=list->header;
        while(!(temp->ratio>=new_node->ratio && temp->ptr->ratio<=new_node->ratio))
        {
            temp=temp->ptr;
        }
        new_node->ptr=temp->ptr;
        temp->ptr=new_node;
        list->count++;
        
        return SUCCESS;
    }
    return FAILURE;
}

void print(List *list)
{
    Node *temp;
    temp=list->header;
   
    while(temp->ptr!=NULL)
    {
        printf("profit :%0.2f ||  weight :%0.2f || Ratio :%0.2f\n",temp->pi,temp->wi,temp->ratio);
        temp=temp->ptr;
    }
    printf("profit :%0.2f ||  weight :%0.2f || Ratio :%0.2f\n",temp->pi,temp->wi,temp->ratio);
}

void print_linked(List *list)
{
    Node *temp;
    temp=list->header;
   
    while(temp->ptr!=NULL)
    {
        printf("%p %f %f %f %p\n",temp,temp->pi,temp->wi,temp->ratio,temp->ptr);
        temp=temp->ptr;
    }
    printf("%p %f %f %f %p\n",temp,temp->pi,temp->wi,temp->ratio,temp->ptr);
    printf("1st address:%p\n",temp);
    printf("1st address:%p\n",list->header);
    printf("tail address:%p\n",list->tail);

}
List* free_list(List*my_list)
{
    Node *temp;

    while(my_list->header != NULL)
    {
        temp = my_list->header;
        my_list->header = my_list->header->ptr;
        free(temp);
    }
    free(my_list);

    return NULL;
}

void calculate(List *list)
{
    
    Node *temp;
    temp=list->header;
    int cnt=list->count;
    while(cnt>0)
    {
        
        if(temp->wi<=list->max && list->max>0)
        {
            list->max=list->max - temp->wi;
            list->profit=list->profit+temp->pi;
            
           
        }
        else if(temp->wi>list->max && list->max>0)
        {
            list->profit=(temp->pi/temp->wi)*list->max+list->profit;
            list->max=0;
            

           
        }
        cnt--;
        printf("%d %f\n",cnt,list->profit);
        temp=temp->ptr;
    }
    

}