#include<stdio.h>

#include "queue.h"

int main()
{
    Queue* line = intialize_queue(3);
        printf("enque: %i\n",enqueue(line,10));
        printf("front: %i, rear: %i\n",line->front, line->rear);
        printf("deque: %i \n",dequeue(line));
        printf("front: %i, rear: %i\n",line->front, line->rear);
        printf("en: %i\n",enqueue(line,20));
        printf("front: %i, rear: %i\n",line->front, line->rear);
        printf("en: %i\n",enqueue(line,30));
        printf("front: %i, rear: %i\n",line->front, line->rear);
        printf("en: %i\n",enqueue(line,40));
        printf("front: %i, rear: %i\n",line->front, line->rear);

        printf("flag: %i\n",enqueue(line,50)); // 0
        printf("front: %i, rear: %i\n",line->front, line->rear);

       printf("de: %i \n",dequeue(line));
        printf("de: %i \n",dequeue(line));
        printf("de: %i \n",dequeue(line));
        printf("de: %i \n",dequeue(line));
        printf("front: %i, rear: %i\n",line->front, line->rear);
        printf("en: %i\n",enqueue(line,40));
        printf("front: %i, rear: %i\n",line->front, line->rear);
        printf("flag: %i",enqueue(line,100));
}