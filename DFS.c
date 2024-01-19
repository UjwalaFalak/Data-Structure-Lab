#include <stdio.h>
#include <stdlib.h>

int source_node,Vertex,Edge,time,visited[10],Graph[10][10];

void DepthFirstSearch(int i)
{
    int j;
    visited[i]=1;
    printf(" %d->",i+1);
    for(j=0;j<Vertex;j++)
    {
        if(Graph[i][j]==1&&visited[j]==0)

            DepthFirstSearch(j);
    }
}

int main()
{
    int i,j,v1,v2;
    printf("\t\t\tDepth_First_Search\n");
    printf("Enter the number of edges:");
    scanf("%d",&Edge);
    printf("Enter the number of vertices:");
    scanf("%d",&Vertex);
    for(i=0;i<Vertex;i++)
    {
        for(j=0;j<Vertex;j++)
            Graph[i][j]=0;
    }
    for(i=0;i<Edge;i++)
    {
        printf("Enter the edges (V1 V2) : ");
        scanf("%d%d",&v1,&v2);
        Graph[v1-1][v2-1]=1;
    }
    for(i=0;i<Vertex;i++)
    {
        for(j=0;j<Vertex;j++)
            printf(" %d ",Graph[i][j]);
        printf("\n");
    }
    printf("Enter the source: ");
    scanf("%d",&source_node);
    DepthFirstSearch(source_node-1);
    return 0;
}