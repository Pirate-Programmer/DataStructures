#include"stack.h"

#define Error 404;


int main(int argc, char* argv[])
{
    
    Stack* clothes = intialize_stack(10);
    printf("%i", peek(clothes));
    for(int i = 1; i <= 10; i++)
    {
       // printf("top: %i capacity: %i\n",clothes->top,clothes->capacity);
        push(clothes, i);
    }
    printf("Top of Stack: %i",pop(clothes));

    freeStack(clothes);
}


