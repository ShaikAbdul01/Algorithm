#include <stdio.h>

void heapify(int ar[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ar[left] > ar[largest])
    {
        largest = left;
    }
    if (right < n && ar[right] > ar[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = ar[i];
        ar[i] = ar[largest];
        ar[largest] = temp;
        heapify(ar, n, largest);
    }
}
void heapSort(int ar[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ar, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = ar[0];
        ar[0] = ar[i];
        ar[i] = temp;

        heapify(ar, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int ar[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    heapSort(ar, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}

/*
Enter the number of elements: 6
Enter the elements: 5 30 40 20 15 10
Sorted array: 5 10 15 20 30 40


 */

// Min heap

/*
#include <stdio.h>

// Function to heapify a subtree rooted at index i in the array ar[] of size n
void heapify(int ar[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;   // Left child index
    int right = 2 * i + 2;  // Right child index

    // If left child is smaller than root
    if (left < n && ar[left] < ar[smallest])
        smallest = left;

    // If right child is smaller than the smallest so far
    if (right < n && ar[right] < ar[smallest])
        smallest = right;

    // If the smallest is not the root
    if (smallest != i)
    {
        // Swap the smallest child with the root
        int temp = ar[i];
        ar[i] = ar[smallest];
        ar[smallest] = temp;

        // Recursively heapify the affected subtree
        heapify(ar, n, smallest);
    }
}

// Function to build a Min Heap from the input array
void buildMinHeap(int ar[], int n)
{
    // Start from the last non-leaf node and heapify all subtrees in bottom-up manner
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(ar, n, i);
    }
}

// Function to perform Heap Sort (Min Heap) on array ar[] of size n
void heapSort(int ar[], int n)
{
    // Build a Min Heap from the input array
    buildMinHeap(ar, n);

    // One by one extract elements from the Min Heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move the current root (smallest element) to the end
        int temp = ar[0];
        ar[0] = ar[i];
        ar[i] = temp;

        // Call heapify on the reduced heap (excluding the sorted elements)
        heapify(ar, i, 0);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int ar[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }

    // Perform Heap Sort (Min Heap)
    heapSort(ar, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }

    return 0;
}


 */