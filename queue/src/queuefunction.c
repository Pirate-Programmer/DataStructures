
#include "queue.h"

Queue* intialize_queue(unsigned int capacity)
{
    Queue* queue = (Queue* )malloc(sizeof(Queue));
    if(queue == NULL)
        return NULL;

    queue->queue = (Objects* )malloc(sizeof(Objects)*capacity);
    if(queue == NULL)
    {
        free(queue);
        return NULL;
    }
    
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
}


//checks if queue is empty
//when front = -1 OR front ptr ahead of rear ptr then queue is empty
bool isEmpty(Queue* queue)
{
    if(queue->front == -1 || queue->front > queue->rear)
        return true;

    return false;
}

//queue is full
//when rear ptr == capacity of the queue(array)
bool isFull(Queue* queue)
{

    return (queue->rear == queue->capacity - 1) && (queue->front <= queue->rear);
}

//rear++;
//add element in back
//for first element set front = 0
bool enqueue(Queue* queue, Objects object)
{
    if(queue == NULL || isFull(queue))
        return false;
    
    if(isEmpty(queue))
    {
        queue->front = 0;
        queue->rear = -1;
    }
        
    queue->queue[++queue->rear] = object;
    return true;
}

//element from front is removed
//then front++
Objects dequeue(Queue* queue)
{
    if(queue == NULL || isEmpty(queue))
        return '\0';
    
    return  queue->queue[queue->front++];
}

Objects peek_front(Queue* queue)
{
    if(queue == NULL || isEmpty(queue))
        return '\0';
    return queue->queue[queue->front];
}

Objects peek_rear(Queue* queue)
{
    if(queue == NULL || isEmpty(queue))
        return '\0';
    return queue->queue[queue->rear];
}

