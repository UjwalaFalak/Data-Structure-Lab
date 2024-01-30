#include<stdio.h>
#include<stdlib.h>
int arr[10][10],queue[10],visited[10],n,i,j,front=0,rear=-1;
void BFS(int ver)
{
  for(i=1;i<=n;i++)
  {
    if(arr[ver][i] && !visited[i])
    	queue[++rear]=i;
    if(front<=rear) 
    {
     	visited[queue[front]]=1;
     	BFS(queue[front++]);
    }
  }
}
int main()
{
  int x;
  printf("\nenter the number of vertices");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {  queue[i]=0;
     visited[i]=0;
  }
   printf("\nenter the graph value in the form of matrix\n");
  for(i=1;i<=n;i++)
  	for(j=1;j<=n;j++)
  		scanf("%d",&arr[i][j]);
  printf("\nenter the source node\n");
  scanf("%d",&x);
  BFS(x);
  printf("the nodes which are reachable are\n");
  for(i=1;i<=n;i++)
  {
  	if(visited[i])
  		printf("%d\t",i);
  	else
  		printf("\nBFS not possible");
  }
  return 0;
}
