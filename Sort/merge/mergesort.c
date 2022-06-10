#include <stdio.h>

int arr[1000000];
int result[1000000];

void merge_sort(int left, int right)
{
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
        if (arr[i] > arr[j])
            result[k++] = arr[j++];
        else
            result[k++] = arr[i++];

    if (i > mid)
        while (j <= right)
            result[k++] = arr[j++];
    else
        while (i <= mid)
            result[k++] = arr[i++];

    for (k = left; k <= right; k++)
        arr[k] = result[k];
}

void devide(int left, int right)
{
    if (left != right)
    {
        int mid = (left + right) / 2;
        devide(left, mid);
        devide(mid + 1, right);
        merge_sort(left, right);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    devide(0, N - 1);

    for(int i = 0; i < N; i++)
        printf("%d\n", arr[i]);

    return (0);
}