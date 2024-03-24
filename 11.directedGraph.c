#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int arr[m][2];

    printf("Enter the edges (in format 'source destination'):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    // For Adjacency Matrix
    int Adj[n + 1][n + 1];

    // Initialize the adjacency matrix with 0s
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            Adj[i][j] = 0;
        }
    }

    // Traverse the array of edges
    for (int i = 0; i < m; i++) {
        // Find X and Y of edges
        int x = arr[i][0];
        int y = arr[i][1];

        // Update value to 1
        Adj[x][y] = 1; // for directed graph, only set one direction
    }

    // Print Adjacency Matrix
    printf("Adjacency Matrix:\n");
    // Traverse the Adj[][]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Print the value at Adj[i][j]
            printf("%d ", Adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
