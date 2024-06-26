#include <stdio.h>

int main()
{
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int arr[m][2];

    printf("Enter the edges (in format 'source destination'):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    // For Adjacency Matrix
    int Adj[n + 1][n + 1];

    // Function call to create Adjacency Matrix
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            Adj[i][j] = 0;
        }
    }

    // Traverse the array of Edges
    for (int i = 0; i < m; i++)
    {
        // Find X and Y of Edges
        int x = arr[i][0];
        int y = arr[i][1];

        // Update value to 1
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }

    // Print Adjacency Matrix
    printf("Adjacency Matrix:\n");
    // Traverse the Adj[][]
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // Print the value at Adj[i][j]
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*
Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges (in format 'source destination'):
1 2
1 3
2 4
2 5
3 4
4 5
Adjacency Matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 1 0
0 1 1 0 1
0 1 0 1 0

 */