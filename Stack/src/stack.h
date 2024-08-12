#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include<limits.h>

typedef int Objects;

typedef struct 
{
    //int top: contains the top index so in a way top of stack.
    //top of stack == array + top;.
    //equilvalent to stack->objects[top] 

    int top; 
    Objects* objects; //this can be any other datatype pointer acc'n to the situation.

    //unsigned int capacity: contains the max size of stack.
    //if top == capacity-1 ie stack is full then resize stack.
    unsigned int capacity;
}Stack;


 Stack* intialize_stack(unsigned int capacity); //intialize stack of size: capacity

 bool isEmpty(Stack* stack); //check if stack is empty


// used as a internal function by push
//resize stack inc/dec (as of now only doubles the capacity)
bool resize_stack(Stack* stack);

//push element on top of stack
bool push(Stack* stack,int object);

//pop element from top of stack
Objects pop(Stack* stack);

void freeStack(Stack* stack);

Objects peek(Stack* stack);


#endif