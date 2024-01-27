#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
}NODE;
NODE *list[10];   // array of pointers

void creatematrix(int m[10][10], int n)
{
    int i,j;
    char ans;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        m[i][i]=0;
        if(i!=j)
        {
            printf("\n Is ther an edge between %d and %d (1/0) :",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
    }
}
void displaymatrix(int m[10][10],int n)
{
    int i,j;
    printf("\n The adjacency matrix is :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
          printf("%d ",m[i][j]);
        printf("\n");
    }
}

void createlist(int m[10][10],int n)
{
    int i,j;
    struct node *temp,*newnode;
    for(i=0;i<n;i++)
    {
        list[i]=NULL;
        for(j=0;j<n;j++)
        {
            if(m[i][j]==1)
            {
                newnode= (NODE *)malloc(sizeof(NODE));
                newnode->vertex=j+1;
                newnode->next=NULL;
                if(list[i] == NULL)
                   list[i]=temp=newnode;
                else
                {
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }
}
void displist(int n)
{
    struct node *temp;
    int i;
    printf("\n The adjacency list is : \n");
    for(i=0;i<n;i++)
    {
        printf("\n v%d -->",i+1);
        temp=list[i];
        while (temp)
        {
            printf("v%d--> ",temp->vertex);
            temp=temp->next;
        }
        printf("NULL");
    }
}

void degree_graph(int m[10][10],int n)
{
    int  sum_in,sum_out,v,i;
    printf("\n\n Vertex Indegree Outdegree Total degree \n");
    
    for(v=0;v<n;v++)
    {
        sum_in =sum_out =0;
        for(i=0;i<n;i++)
        {
           sum_in = sum_in + m[i][v];  //sum of column v
           sum_out =sum_out + m[v][i];  //sum of row v
           
        }
        printf("%d\t%d\t%d\t%d\n",v+1,sum_in,sum_out, sum_in+sum_out);
    }
}

int main()
{
    int m[10][10],n;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    creatematrix(m,n);
    displaymatrix(m,n);
    createlist(m,n);
    displist(n);
    degree_graph(m,n);
}

/* OUTPUT
 Enter the number of vertices:4

 Is ther an edge between 1 and 2 (1/0) :1

 Is ther an edge between 1 and 3 (1/0) :1

 Is ther an edge between 1 and 4 (1/0) :0

 Is ther an edge between 2 and 1 (1/0) :0

 Is ther an edge between 2 and 3 (1/0) :1

 Is ther an edge between 2 and 4 (1/0) :1

 Is ther an edge between 3 and 1 (1/0) :1

 Is ther an edge between 3 and 2 (1/0) :1

 Is ther an edge between 3 and 4 (1/0) :0

 Is ther an edge between 4 and 1 (1/0) :0

 Is ther an edge between 4 and 2 (1/0) :0

 Is ther an edge between 4 and 3 (1/0) :0

 The adjacency matrix is :
0 1 1 0 
0 0 1 1 
1 1 0 0 
0 0 0 0 

 The adjacency list is : 

 v1 -->v2--> v3--> NULL
 v2 -->v3--> v4--> NULL
 v3 -->v1--> v2--> NULL
 v4 -->NULL

 Vertex Indegree Outdegree Total degree 
1       1       2       3
2       2       2       4
3       2       2       4
4       1       0       1
*/
