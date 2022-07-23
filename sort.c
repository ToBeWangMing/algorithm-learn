#include <stdio.h>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x)   sizeof((x)) / (sizeof(x[0]))
#endif

static void dumpArray(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i != len - 1)
            printf(" ");
    }
    printf("\n");
}

static void swap(int *arr, int index1, int index2)
{
    int temp;
    temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

static void sortBySelection(int *arr, int len)
{
    if (arr == NULL || len < 2)
        return;

    for (int i = 0; i < len; i++) {
        int minValueIndex = i;
#if 0
        for (int j = minValueIndex + 1; j < len; j++) {
            if (arr[minValueIndex] > arr[j])
                swap(arr, minValueIndex, j);
        }
#else
        for (int j = minValueIndex + 1; j < len; j++) {
            minValueIndex = arr[minValueIndex] > arr[j] ? j : minValueIndex;
        }
        swap(arr, i, minValueIndex);
#endif
    }
}

static void sortByBubble(int *arr, int len)
{
    if (arr == NULL || len < 2)
        return;

    for (int end = len - 1; end >= 0; end--) {
        for (int j = 0; j < end; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}

static void sortByInsertion(int *arr, int len)
{
    if (arr == NULL || len < 2)
        return;

    for (int end = 1; end < len; end++) {
        int newNumIdx = end;
#if 1
        while (newNumIdx - 1 >= 0 && arr[newNumIdx - 1] > arr[newNumIdx]) {
            swap(arr, newNumIdx - 1, newNumIdx);
            newNumIdx--;
        }
#else
        while (newNumIdx - 1 >= 0) {
            if (arr[newNumIdx - 1] > arr[newNumIdx])
                swap(arr, newNumIdx - 1, newNumIdx);
            newNumIdx--;
        }
#endif
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {7, 1, 3, 5, 1, 6, 8, 1, 3, 5, 7, 5, 6};
    int len = ARRAY_SIZE(arr);

    dumpArray(arr, len);
    sortByInsertion(arr, len);
    dumpArray(arr, len);

    return 0;
}