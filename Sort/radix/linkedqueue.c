#include "linkedqueue.h"

Linkedqueue* createLinkedQueue()
{
    Linkedqueue *queue;

    queue = (Linkedqueue *)calloc(1, sizeof(Linkedqueue));
    return (queue);
}
int enqueueLQ(Linkedqueue* pQueue, queueNode element)
{
    queueNode   *newNode;

    newNode = (queueNode*)calloc(1, sizeof(queueNode));
    newNode->data = element.data;
    if (!pQueue->currentElementCount)
    {
        pQueue->pFrontNode = newNode;
        pQueue->pRearNode = newNode;
    }
    else
    {
        pQueue->pRearNode->pLink = newNode;
        pQueue->pRearNode = newNode;
    }
    pQueue->currentElementCount++;
    return (TRUE);
}
queueNode* dequeueLQ(Linkedqueue* pQueue)
{
    queueNode *retNode;

    retNode = (queueNode*)calloc(1, sizeof(queueNode));
    if (isLinkedQueueEmpty(pQueue))
        return (NULL);
    retNode = pQueue->pFrontNode;
    if (pQueue->currentElementCount == 1)
    {
        pQueue->pFrontNode = NULL;
        pQueue->pRearNode = NULL;
    }
    else
    {
        pQueue->pFrontNode = pQueue->pFrontNode->pLink;
        retNode->pLink = NULL;
    }
    pQueue->currentElementCount--;
    return (retNode);
}
queueNode* peekLQ(Linkedqueue* pQueue)
{
    if (isLinkedQueueEmpty(pQueue))
        return (NULL);
    return (pQueue->pFrontNode);
}
void deleteLinkedQueue(Linkedqueue* pQueue)
{
    if (isLinkedQueueEmpty(pQueue))
    {
        free(pQueue);
        return ;
    }
    while (pQueue->currentElementCount)
        free(dequeueLQ(pQueue));
    free(pQueue);
    memset(pQueue, 0, sizeof(Linkedqueue));
}

int isLinkedQueueFull(Linkedqueue* pQueue)
{
    return (FALSE);
}
int isLinkedQueueEmpty(Linkedqueue* pQueue)
{
    return (pQueue->currentElementCount == 0);
}