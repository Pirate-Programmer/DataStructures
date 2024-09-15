#include"cll.h"
#include<stdio.h>
node* add(node* list, Object data, int flag)
{
    node* temp = (node* )malloc(sizeof(node));
    if(temp == NULL)
        return list;

    temp->data = data;
    
    if(list == NULL)
    {
        temp->next = temp;  
        return temp;
    }

    node* iterator = list;
    while(iterator->next != list)  //iterating till last node
        iterator = iterator->next;
    iterator->next = temp;  
    temp->next = list;

    if(flag == 1) list = temp; 
    return list;
}

node* append(node* list, Object data)
{
    return add(list, data, 0);
}

node* prepend(node* list, Object data)
{
    return add(list, data, 1);
}

void print(node* list)
{
    if(list == NULL)
        return;
    node* head =  list;
    do
    {
        printf("%d ",list->data);
        list = list->next;
    }while(list != head);
}