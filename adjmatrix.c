#include <stdio.h>
#define MAX_VERTICES 100

int main() 
{
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize the adjacency matrix with zeros
    int numVertices, numEdges;
    int i, j, u, v;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (u, v):\n");
    for (i = 0; i < numEdges; i++) 
    {
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < numVertices; i++) 
    {
        for (j = 0; j < numVertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}