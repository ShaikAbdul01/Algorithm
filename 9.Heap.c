#include <stdio.h>
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
