#ifndef CQueue_H
#define CQueue_H


#include<stdlib.h>
#include<stdbool.h>



typedef int Objects;  // datatype stored in CQueue


typedef struct 
{
    int front;  //front ptr ie loc array
    int rear;  //rear ptr ie loc in array
    Objects* queue;

     unsigned int capacity; //max size of CQueue
}CQueue;

CQueue* intialize_CQueue(unsigned int capacity);
bool enqueue(CQueue* queue, Objects object);
Objects dequeue(CQueue* queue);
bool isEmpty(CQueue* queue);
bool isFull(CQueue* queue);
Objects peek_front(CQueue* queue);
Objects peek_rear(CQueue* queue);

#endif