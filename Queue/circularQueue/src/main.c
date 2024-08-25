#include<stdio.h>

#include "CQueue.h"

int main()
{
    CQueue* queue = intialize_CQueue(3);
    printf("dequeue: %i\n",dequeue(queue));
    printf("enque: %i\n",enqueue(queue,10));
    printf("front: %i  rear: %i\n",queue->front, queue->rear);
    printf("dequeue: %i\n",dequeue(queue));
    printf("front: %i  rear: %i\n",queue->front, queue->rear);
    printf("enque: %i\n",enqueue(queue,20));
    printf("enque: %i\n",enqueue(queue,30));
    printf("enque: %i\n",enqueue(queue,40));
    printf("front: %i  rear: %i\n",queue->front, queue->rear);
    printf("dequeue: %i\n",dequeue(queue));
    printf("front: %i  rear: %i\n",queue->front, queue->rear);
    printf("enque: %i\n",enqueue(queue,30));
    printf("enque: %i\n",enqueue(queue,40));
    printf("front: %i  rear: %i\n",queue->front, queue->rear);
}