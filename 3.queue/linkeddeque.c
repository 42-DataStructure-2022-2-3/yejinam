#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
    LinkedDeque *deque;

    deque = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
    return (deque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode *newNode;

    newNode = (DequeNode *)calloc(1, sizeof(DequeNode));
    newNode->data = element.data;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = newNode;
        pDeque->pRearNode = newNode;
    }
    else
    {
        pDeque->pFrontNode->pLLink = newNode;
        newNode->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode = newNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}
int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode *newNode;

    newNode = (DequeNode *)calloc(1, sizeof(DequeNode));
    newNode->data = element.data;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = newNode;
        pDeque->pRearNode = newNode;
    }
    else
    {
        pDeque->pRearNode->pRLink = newNode;
        newNode->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = newNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}
DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
    DequeNode *retNode;

    if (isLinkedDequeEmpty(pDeque))
        return (NULL);
    retNode = pDeque->pFrontNode;
    if (pDeque->currentElementCount == 1)
    {
        pDeque->pFrontNode = NULL;
        pDeque->pRearNode = NULL;
    }
    else
    {
        pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
        pDeque->pFrontNode->pLLink = NULL;
        retNode->pRLink = NULL;
    }
    pDeque->currentElementCount--;
    return (retNode);
}
DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
    DequeNode *retNode;

    if (isLinkedDequeEmpty(pDeque))
        return (NULL);
    retNode = pDeque->pRearNode;
    if (pDeque->currentElementCount == 1)
    {
        pDeque->pFrontNode = NULL;
        pDeque->pRearNode = NULL;
    }
    else
    {
        pDeque->pRearNode = pDeque->pRearNode->pLLink;
        pDeque->pRearNode->pRLink = NULL;
        retNode->pLLink = NULL;
    }
    pDeque->currentElementCount--;
    return (retNode);
}
DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    if (isLinkedDequeEmpty(pDeque))
        return (NULL);
    return(pDeque->pFrontNode);
}
DequeNode* peekRearLD(LinkedDeque* pDeque)
{
    if (isLinkedDequeEmpty(pDeque))
        return (NULL);
    return(pDeque->pRearNode);
}
void deleteLinkedDeque(LinkedDeque* pDeque)
{
    if (isLinkedDequeEmpty(pDeque))
    {
        free(pDeque);
        return ;
    }
    while (pDeque->currentElementCount)
    {
        free(deleteFrontLD(pDeque));
    }
    free(pDeque);
    return ;
}
int isLinkedDequeFull(LinkedDeque* pDeque)
{
    return (FALSE);
}
int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    return (pDeque->currentElementCount == 0);
}
void	displayLinkedDeque(LinkedDeque* pDeque);