#include <stdio.h>

int main()
{
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int ar[n];

    printf("\nEnter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] == key)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("Element found in the array.\n");
    }
    else
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}
