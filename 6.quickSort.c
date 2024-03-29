#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quickSort(int *ar, int low, int high)
{
    int pivot, i, j;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (ar[i] <= ar[pivot])
            {
                i++;
            }
            while (ar[j] > ar[pivot])
                j--;
            if (i < j)
            {
                swap(&ar[i], &ar[j]);
            }
        }
        swap(&ar[pivot], &ar[j]);
        /*
        quickSort(ar, low, j - 1); sorts the left subarray before the pivot. Here, low remains the same, but the upper bound high becomes j - 1, indicating that we're sorting the subarray from index low to j - 1.
quickSort(ar, j + 1, high); sorts the right subarray after the pivot. Here, low becomes j + 1, indicating that we're sorting the subarray from index j + 1 to high, while high remains the same.
         */
        quickSort(ar, low, j - 1);
        quickSort(ar, j + 1, high);
    }
}
int main()
{
    printf("Enter the value: ");
    int n;
    scanf("%d", &n);
    int ar[n];
    printf("\nEnter the arrya elements:  ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    quickSort(ar, 0, n - 1);
    printf("\nSorting Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    // printf("\n");
    return 0;
}

/* 
Enter the value: 5

Enter the arrya elements:  24 15 2 45 10

Sorting Array: 2 10 15 24 45 
 */