#include "linkedqueue.h"

int getDigit(int arr[], int N)
{
    int max = 0;
    int len;
    for(int i = 0; i < N; i++)
    {
        int tmp = arr[i];
        len = 1;
        while (tmp >= 10)
        {
            tmp /= 10;
            len++;
        }
        if (len > max)
            max = len;
    }
    return max;
}

void radix(int arr[], int N)
{
    int max = getDigit(arr, N);
    int pow = 1;
    int index = 0;
    Linkedqueue *bucket[10];

    for(int i = 0; i < 10; i++)
        bucket[i] = createLinkedQueue();

    for(int i = 0; i < max; i++)
    {
        for(int j = 0; j < N; j++)
        {
            queueNode tmpInNode;
            tmpInNode.data = arr[j];
            int idx = (arr[j] / pow) % 10;
            enqueueLQ(bucket[idx], tmpInNode);
        }

        for(int k = 0; k < 10; k++)
        {
            while(bucket[k]->currentElementCount)
            {
                queueNode *tmpOutNode;
                tmpOutNode = dequeueLQ(bucket[k]);
                arr[index] = tmpOutNode->data;
                free(tmpOutNode);
                index++;
            }
            
        }
        /// 중간 점검
        printf("--------%d------\n", pow); //pow자리 정렬, vscode는 한글이 안나와서 주석달아용..
        for(int i = 0; i < N; i++)
            printf("%d ", arr[i]);
        printf("\n");
        /// 중간점검
        index = 0;
        pow *= 10;
    }
}

int main()
{
    int N = 9;
    int arr[] = {5, 35, 208, 48, 17, 546846, 93 , 103, 478};

    radix(arr, N);

    printf("----sorted array-----\n");
    for(int i = 0; i < N; i++)
        printf("%d ", arr[i]);
}