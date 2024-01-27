#include<stdio.h>
#include<stdlib.h>
#define maxnode 4

typedef struct node
{
   int vertexnum;
    Struct node *next;
}node;
typedef struct list
{
    Node * head;
}list;
list * adjlist[maxnode]={0};

void main()
{
	int i;
	for(i=0;i<maxnode;i++)
	{
		adjlist[i]=(list *)malloc(sizeof(list));
		adjlist[i]->head=NULL;
	}
addnode(0,1);
addnode(0,3);
addnode(1,2);
printlist();
}

void addnode(int s,int d)
{
	Node *src,*temp,*dest;
	if(adjlist[s]->head==NULL)
	{
		src=(node *)malloc(sizeof(node));
		src->vertexnum=s;
		src->next=NULL;
		djlist[s]->head=src;
	}
	dest=(node *)malloc(sizeof(node));
	dest->vertexnum=d;
	src->next=NULL;
	temp=djlist[s]->head;
	while(temp->next!=NULL)
	temp->temp->next;
	temp->next=dest;
    }
}
 void printlist()
{
int i;
	for(i=1;i<maxnode;++i)
	{
		node *p=adjlist[i]->head;
		printf(“Adjacency list of vertex%d”,i);
		while(p)
		{
			printf(“%d”,p->vertexnum);
			p=p->next;
		}
	printf(“\n”);
}
