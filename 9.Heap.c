/* #include <stdio.h>
void insertHeap(int heap[], int *size, int element)
{
    int i = (*size)++;
    while (i > 0 && element > heap[(i - 1) / 2])
    {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = element;
}
int main()
{
    int heap[100];
    int size = 0;
    char choice;

    while (1)
    {
        int element;
        printf("\nEnter element to insert into the heap: ");
        scanf("%d", &element);
        insertHeap(heap, &size, element);
        printf("Heap: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", heap[i]);
        }
    }
    return 0;
}
 */

#include <stdio.h>

#define MAX_HEAP_SIZE 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n, value, heapSize = 0;
    int heap[MAX_HEAP_SIZE];
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        int current = heapSize;
        heap[heapSize++] = value;

        while (current > 0 && heap[current] > heap[(current - 1) / 2])
        {
            swap(&heap[current], &heap[(current - 1) / 2]);
            current = (current - 1) / 2;
        }
    }

    printf("Max Heap: ");
    for (int i = 0; i < heapSize; i++)
    {
        printf("%d ", heap[i]);
    }

    return 0;
}
