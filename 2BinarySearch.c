#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int ar[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int low = 0, high = n - 1, flag = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (ar[mid] == key)
        {
            flag = 1;
            break;
        }
        else if (ar[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (flag == 1)
    {
        printf("Element found.\n");
    }
    else
    {
        printf("Element not found.\n");
    }
    return 0;
}
