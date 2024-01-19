#include<stdio.h>
#include<stdlib.h>

int twodimarray[10][10],queue[10],visited[10],n,i,j,front=0,rear=-1;

void breadthfirstsearch(int vertex) // breadth first search function
{
      for (i=1;i<=n;i++)
      if(twodimarray[vertex][i] && !visited[i])
      queue[++rear]=i;
      if(front<=rear)
      {
            visited[queue[front]]=1;
            breadthfirstsearch(queue[front++]);
      }
}

int main()
{
      int x;
      printf("\n Enter the number of vertices:");
      scanf("%d",&n);
      for (i=1;i<=n;i++)
      {
            queue[i]=0;
            visited[i]=0;
      }
      printf("\n Enter graph value in form of matrix:\n");
      for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                  scanf("%d",&twodimarray[i][j]);
                  printf("\n Enter the source node:");
                  scanf("%d",&x);
                  breadthfirstsearch(x);
                  printf("\n The nodes which are reachable are:\n");
      for (i=1;i<=n;i++)
      if(visited[i])
            printf("%d\t",i);
      else
            printf("\n Breadth first search is not possible");
      return 0;
}