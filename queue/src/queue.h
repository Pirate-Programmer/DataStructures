#ifndef QUEUE_H
#define QUEUE_H


#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef int Objects;  // datatype stored in queue


typedef struct 
{
    int front;  //front ptr ie loc array
    int rear;  //rear ptr ie loc in array
    Objects* queue;

    unsigned int capacity; //max size of queue
}Queue;

Queue* intialize_queue(unsigned int capacity);
bool enqueue(Queue* queue, Objects object);
Objects dequeue(Queue* queue);
bool isEmpty(Queue* queue);
bool isFull(Queue* queue);
Objects peek_front(Queue* queue);
Objects peek_rear(Queue* queue);

#endif