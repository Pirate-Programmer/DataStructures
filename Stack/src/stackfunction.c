
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
    Objects* array = (Objects* )malloc(capacity*(sizeof(Stack)));
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

bool resize_stack(Stack* stack)
{
    //allocate the double the memory
    //call realloc to handle the shifting and memory allocation
    Objects* new_objects_ptr = (Objects* )realloc(stack->objects,stack->capacity*2); 
    if(new_objects_ptr == NULL)
    {
        printf("Realloc operation failed\n");
        return false;
    }
    
    stack->capacity *= 2;
    stack->objects = new_objects_ptr;
   // printf("Resize new capacity: %i \n",stack->capacity);
    return true;
}

//to push element
//inc top of stack
//add the object
bool push(Stack* stack, int object)
{
    /*
    example:
    capacity: 10
    top: 8 ie the 9th object
    no resize

    after push ie the 10th element
    before push : top = 8 and capacity - 1 = 9
    after push : top: 9 and capacity - 1 = 9 ie now all 10 objects are filled
    on next push call resize before pushing the object on top of stack
    */
    if(stack->top == stack->capacity-1) //stack is full
    {
        if(!resize_stack(stack))
        {
            freeStack(stack);
            return false;
        }
    }
    stack->top++;
    *(stack->objects + stack->top) = object;

      return true;
}

//to pop element
// value =  *(objects + top)
//dec top of stack
//return value

//If Int min is the smallest negative value int can store
//is this is returned ie stact is empty
Objects pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        return INT_MIN;
    }
    Objects value = *(stack->objects + stack->top);
    stack->top--;
    return value;
}

void freeStack(Stack* stack)
{
    free(stack->objects);
    free(stack);
}

//int min returned ie stack is empty
Objects peek(Stack* stack)
{
    if(isEmpty(stack)){
        return INT_MIN;
    }
    return *(stack->objects+stack->top); 
}
