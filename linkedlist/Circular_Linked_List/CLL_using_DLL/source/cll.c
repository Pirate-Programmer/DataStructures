#include"cll.h"
#include<stdio.h>

node* add(node* list, Object data,int flag)
{
    node* temp = (node* )malloc(sizeof(node));
    if(temp == NULL)
        return list;

    temp->data = data;
    if(list == NULL)
    {
        temp->prev = temp;
        temp->next = temp;
        return temp;
    }

    temp->next = list;
    temp->prev = list->prev;
    list->prev->next = temp;
    list->prev = temp;
    
    if(flag == 1) list = temp; //for prepend
    return list;
}


node* append(node* list, Object data)
{
    return add(list, data, 0);
}

node* prepend(node* list, Object data)
{
    return add(list,data,1);
}

void print(node* list)
{
    if(list == NULL)
        return;
    node* head = list;
    do
    {
        printf("%d ",list->data);
        list = list->next;
    }while (list != head);
    printf("\n");
}