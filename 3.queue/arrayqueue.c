#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue *queue;

    queue = (ArrayQueue*)calloc(1, sizeof(ArrayQueue));
    queue->maxElementCount = maxElementCount;
    queue->pElement = (ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));

    return (queue);
}
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if (isArrayQueueFull(pQueue))
        return (FALSE);

    pQueue->pElement[++(pQueue->rear)].data = element.data;

    pQueue->currentElementCount++;
    return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    ArrayQueueNode  *retNode;

    if(isArrayQueueEmpty(pQueue))
        return (NULL);
    retNode = (ArrayQueueNode *)calloc(1, sizeof(ArrayQueueNode));
    *retNode = pQueue->pElement[pQueue->front + 1];
    pQueue->pElement[pQueue->front + 1].data = 0;
    pQueue->front++;
    pQueue->currentElementCount--;

    return (retNode);
}
ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{

    ArrayQueueNode  *retNode;

    if(isArrayQueueEmpty(pQueue))
        return (NULL);
    retNode = (ArrayQueueNode *)calloc(1, sizeof(ArrayQueueNode));
    *retNode = pQueue->pElement[pQueue->front + 1];
    return (retNode);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
    free(pQueue->pElement);
    free(pQueue);
    memset(pQueue, 0, sizeof(ArrayQueue));
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
    return (pQueue->currentElementCount == pQueue->maxElementCount);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    return (pQueue->currentElementCount == 0);
}

void printArrayQueue(ArrayQueue *pQueue)
{
    for (int i = pQueue->front + 1; i < pQueue->rear + 1; i++)
    {
        printf("%c, ",pQueue->pElement[i].data);
    }
    printf("\n");
}
