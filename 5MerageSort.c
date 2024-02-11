#include <stdio.h>

void Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // created temporary array
    int Left[n1], Right[n2];

    // copying the data from arr to temporary array
    for (int i = 0; i < n1; i++)
    {
        Left[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        Right[j] = arr[mid + 1 + j];
    }

    // merging of the array
    int i = 0, j = 0, k = left;
    // intital index of first subarray
    // inital index of second subarray
    // initial index of parent array
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    // copying the elements from Left[], if any
    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    // copying the elements from Right[], if any
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

void Merge_Sort(int *ar, int left, int right)
{
    if (left < right)
    {

        int mid = (left + right) / 2;
        Merge_Sort(ar, left, mid);
        Merge_Sort(ar, mid + 1, right);
        Merge(ar, left, mid, right);
    }
}

int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int ar[n];
    printf("\nEnter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    Merge_Sort(ar, 0, n - 1);

    printf("\nThe sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    return 0;
}