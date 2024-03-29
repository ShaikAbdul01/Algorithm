#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 20 // Maximum number of vertices allowed

int minDistance(int dist[], bool sptSet[], int v)
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < v; i++)
    {
        if (sptSet[i] == false && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printSolution(int dist[], int v)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < v; i++)
    {
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int v)
{
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];

    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < v - 1; count++)
    {
        int u = minDistance(dist, sptSet, v);
        sptSet[u] = true;

        for (int i = 0; i < v; i++)
        {
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i])
            {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    printSolution(dist, v);
}

int main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    if (v > MAX_VERTICES)
    {
        printf("Number of vertices exceeds the maximum allowed limit.");
        return 1;
    }

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix for the graph (%dx%d):\n", v, v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    dijkstra(graph, 0, v);

    return 0;
}

/*
Enter the number of vertices: 9
Enter the adjacency matrix for the graph (9x9):
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
Vertex           Distance from Source
0                                0
1                                4
2                                12
3                                19
4                                21
5                                11
6                                9
7                                8
8                                14

 */