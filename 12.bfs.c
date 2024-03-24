#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to add an edge to the graph
void addEdge(int *adjList[], int u, int v, int *edgesCount)
{
    adjList[u][(*edgesCount)++] = v;
}

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfs(int *adjList[], int vertices, int startNode, int visited[])
{
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[startNode] = 1;
    queue[rear++] = startNode;

    // Iterate over the queue
    while (front != rear)
    {
        // Dequeue a vertex from queue and print it
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        // Get all adjacent vertices of the dequeued vertex
        // currentNode If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int i = 0; i < MAX_VERTICES; ++i)
        {
            int neighbor = adjList[currentNode][i];
            if (neighbor == -1)
                break;
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
        }
    }
}

int main()
{
    // Number of vertices in the graph
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Adjacency list representation of the graph
    int *adjList[vertices];
    for (int i = 0; i < vertices; ++i)
    {
        adjList[i] = (int *)malloc(MAX_VERTICES * sizeof(int));
        for (int j = 0; j < MAX_VERTICES; ++j)
            adjList[i][j] = -1; // Initialize to -1
    }

    // Number of edges for each vertex
    int edgesCount[vertices];
    for (int i = 0; i < vertices; ++i)
        edgesCount[i] = 0;

    // Add edges to the graph
    int m;
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (in format 'source destination'):\n");
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v, &edgesCount[u]);
    }

    // Mark all the vertices as not visited
    int visited[vertices];
    for (int i = 0; i < vertices; ++i)
        visited[i] = 0;

    // Perform BFS traversal starting from vertex 0
    printf("Breadth First Traversal starting from vertex 0: ");
    bfs(adjList, vertices, 0, visited);

    // Free dynamically allocated memory
    for (int i = 0; i < vertices; ++i)
        free(adjList[i]);

    return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node* adjList[], int u, int v)
{
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfs(struct Node* adjList[], int vertices,
    int startNode, int visited[])
{
    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[startNode] = 1;
    queue[rear++] = startNode;

    // Iterate over the queue
    while (front != rear) {
        // Dequeue a vertex from queue and print it
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        // Get all adjacent vertices of the dequeued vertex
        // currentNode If an adjacent has not been visited,
        // then mark it visited and enqueue it
        struct Node* temp = adjList[currentNode];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Adjacency list representation of the graph
    struct Node* adjList[vertices];
    for (int i = 0; i < vertices; ++i)
        adjList[i] = NULL;

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Add edges to the graph
    printf("Enter edges (format: source destination):\n");
    for (int i = 0; i < edges; ++i) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(adjList, source, destination);
    }

    // Mark all the vertices as not visited
    int visited[vertices];
    for (int i = 0; i < vertices; ++i)
        visited[i] = 0;

    // Perform BFS traversal starting from a specified vertex
    int startVertex;
    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &startVertex);

    printf("Breadth First Traversal starting from vertex %d: ", startVertex);
    bfs(adjList, vertices, startVertex, visited);

    return 0;
}


 */