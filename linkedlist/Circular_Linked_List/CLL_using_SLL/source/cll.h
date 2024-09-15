#ifndef CLL_H
#define CLL_H

#include<stdlib.h>

typedef int Object;

typedef struct node
{
    Object data;
    struct node * next;
}node;

node* prepend(node* list, Object data);
node* append(node* list, Object data);
node* add(node* list, Object data, int flag);
void print(node* list);

#endif