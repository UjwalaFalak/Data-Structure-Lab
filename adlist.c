#include <stdio.h>
#include <stdlib.h>
int no_vertices;
struct node
{
    int data;
    struct node *next;
};
void create_graph(struct node *adj[])
{
    struct node *newnode;
    int i, j, k, data;
    for (i = 0; i <no_vertices; i++)
    {
        struct node *last = NULL;
        printf("\nenter the number of adjacent vertice of %d\t", i);
        scanf("%d", &k);
        for (j = 0; j < k; j++)
        {

            printf("enter the value of %d neighbour of %d ", j, i);
            scanf("%d", &data);
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->next = NULL;
            if (adj[i] == NULL)
            {
                adj[i] = newnode;
            }
            else
            {
                last->next = newnode;
            }
            last = newnode;
        }
    }
}

void print_graph(struct node *adj[]){
    struct node *temp=NULL;
    int i,j;
    for(i=0;i<no_vertices;i++)
    {
        temp=adj[i];
        printf("\nthe neighbours of %d are\t",i);
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp= temp->next;
        }
    }
}
int main()
{
    int i, j;
    printf("\nenter the total no of vertices\t");
    scanf("%d", &no_vertices);
    struct node *adj[no_vertices];
    for (i = 0; i < no_vertices; i++)
    {
        adj[i] = NULL;
    }
    create_graph(adj);
    printf("\nthe elements of the graph are\n");
    print_graph(adj);
    return 0;
}

