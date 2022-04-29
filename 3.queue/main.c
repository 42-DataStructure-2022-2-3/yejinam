#include "arrayqueue.h"

int main()
{
    ArrayQueue      *queue;
    ArrayQueueNode  element;

    
    queue = createArrayQueue(5);
    for (int i = 0; i < 4; i++)
    {
        element.data = 'a' + i;
        enqueueAQ(queue, element);
    }
    for (int i = 0; i < 4; i++)
    {
        dequeueAQ(queue);
    }
    printf("isArrayQueueFull? [%d]\n", isArrayQueueFull(queue));
    printf("isArrayQueueEmpty? [%d]\n", isArrayQueueEmpty(queue));
    printArrayQueue(queue);
    return (0);
}