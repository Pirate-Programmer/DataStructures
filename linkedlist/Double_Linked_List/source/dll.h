#ifndef DLL_H
#define DLL_H

#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

typedef int Object;

typedef struct node
{
    Object data;
    struct node* next;
    struct node* prev; 
}node;

node* prepend(node* list, Object data);
node* append(node* list, Object data);
node* insert(node* head, Object data, int idx);

bool deleteByValue(node** list, Object data);
bool deleteByPosition(node** list,int postion);

node* reverse_iterative(node* list);
node* reverse_recursive(node* list);

int get_length(node* list);
node* get_tail(node* list);

void print_list(node* list);

void print_list_reverse(node* head);
void print_using_tail(node* tail);  //internal function used by print reverse

void free_node(node* list);

#endif