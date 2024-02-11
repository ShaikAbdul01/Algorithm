#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int ar[n];
    printf("\nEnter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] > ar[j])
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}

/*
Worst-case time complexity: O(n*n)=O(n²)
Average time complexity: O(n²)
Best-case time complexity: O(n), the array is already sorted.
space complexity: O(1)
 */