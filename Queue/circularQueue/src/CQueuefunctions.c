#include "CQueue.h"

CQueue* intialize_CQueue(unsigned int capacity)
{
    CQueue* queue = (CQueue* )malloc(sizeof(CQueue));
    if(queue == NULL)
        return NULL;

    queue->queue = (Objects* )malloc(sizeof(Objects)*capacity);
    if(queue->queue == NULL)
    {
        free(queue);
        return NULL;
    }
    
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
}


bool isEmpty(CQueue* queue)
{
    return queue->front == -1;
}

//full when rear ptr one behind front ptr
//% capacity wraps the queue around
bool isFull(CQueue* queue)
{
    return  (((queue->rear + 1)%queue->capacity) == queue->front);
}

//to add element in queue in back
//rear++%capacity 
//then add element
//in circular rear ptr wraps around back
bool enqueue(CQueue* queue, Objects object)
{
    if(queue == NULL || isFull(queue))
        return false;
    
    if(isEmpty(queue))
        queue->front = 0;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->queue[queue->rear] = object;
    return true;
}

//to remove element in queue from front
//remove element
//front++%capacity
//in circular queue front ptr wraps around back
Objects dequeue(CQueue* queue)
{
    if(queue == NULL || isEmpty(queue))
        return '\0';

     Objects temp = queue->queue[queue->front];

     //case when last element remains
     //after dequeue operation queue is reset as it is empty
    if(queue->rear == queue->front) 
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
        queue->front = (queue->front + 1)%queue->capacity;

    return temp;
}

Objects peek_front(CQueue* queue)
{
    if(queue == NULL || isEmpty(queue))
        return '\0';
    return queue->queue[queue->rear];
}

Objects peek_rear(CQueue* queue)
{
    if(queue == NULL || isEmpty(queue))
        return '\0';
    return queue->queue[queue->rear];
}