#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int ar[n];
    printf("\nEnter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    for (int i = 1; i < n; i++)
    {
        int key = ar[i];
        int j = i - 1;

        while (j >= 0 && ar[j] > key)
        {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = key;
    }

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}
