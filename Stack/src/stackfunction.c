#include "Stack.h"

 Stack* intialize_stack(unsigned int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL)
    {
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    int* array = (int* )malloc(capacity*(sizeof(Stack)));
    if(array == NULL)
    {
        return NULL;
    }
    stack->objects = array;

    return stack;
}

bool isEmpty(Stack* stack)
{
    if(stack->top < 0)
        return true;

    return false;
}

Stack* resize_stack(Stack* stack)
{
    //allocate the double the memory
    //call realloc to handle the shifting and memory allocation
    int* new_objects_ptr = realloc(stack->objects,stack->capacity*2); 
    if(new_objects_ptr == NULL)
    {
        printf("Realloc operation failed\n");
        return stack;
    }
    stack->capacity *= 2;
    stack->objects = new_objects_ptr;
}

//to push element
//inc top of stack
//add the object
int push(Stack* stack, int object)
{
    Stack* temp = NULL;
    if(stack->top == stack->capacity-1) //stack is full
    {
        temp = resize_stack(stack);
        if(temp == stack)
        {
            return 1;
        }
        stack = temp;
    }
      stack->top++;
    *(stack->objects + stack->top) = object;
      return 0;
}