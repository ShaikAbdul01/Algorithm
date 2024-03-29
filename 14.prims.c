#include <stdio.h>
#include <stdbool.h>

#define INF 9999999

int main()
{
    int v;
    printf("Enter the vertices: ");
    scanf("%d", &v);
    int G[v][v];      // adjacency matrix to represent graph
    int no_edge = 0;  // number of edges
    bool selected[v]; // to track selected vertices

    // Initialize selected array to false
    for (int i = 0; i < v; i++)
        selected[i] = false;

    // Prompt user to input adjacency matrix values
    printf("Enter the adjacency matrix for the graph (5x5):\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    // Choose the 0th vertex and mark it as selected
    selected[0] = true;

    printf("Edge : Weight\n");

    // Iterate until all vertices are included in the MST
    while (no_edge < v - 1)
    {
        int min = INF;
        int x = 0, y = 0;

        // Traverse the selected vertices
        for (int i = 0; i < v; i++)
        {
            if (selected[i])
            {
                // Check adjacent vertices
                for (int j = 0; j < v; j++)
                {
                    // If vertex not selected and there's an edge
                    if (!selected[j] && G[i][j])
                    {
                        // Update minimum weight and corresponding vertices
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        // Print the selected edge and its weight
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }

    return 0;
}
/*
Enter the vertices: 5
Enter the adjacency matrix for the graph (5x5):
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
Edge : Weight
0 - 1 : 10
0 - 3 : 30
3 - 2 : 20
2 - 4 : 10

 */