/*Write a C program which uses Binary search tree library 
and displays nodes at each level, count of node at each level and total levels in the tree. */

#include <stdio.h>
#include<stdlib.h>
#include "level.h"
int main()
{
    int level,i;
    NODE *root = NULL;
    root = createbst(root);    // Create
    // Traverse
      level=levelorder(root);
// Number of nodes at each level
    for(i=0;i<level;i++)
       printf("\nNumber of nodes at [ %d ] Level :: %d\n",i,NodesAtLevel(root,i));
     return 0;
}


//level.h
#define MAXSIZE 20
typedef struct node
{
    int info;
    struct node *left, *right;
}NODE;

NODE * createbst(NODE *root);
int levelorder(NODE *root);

// Queue functions

typedef struct 
{
    NODE *data[MAXSIZE];
    int front,rear; 
}QUEUE;

void initq(QUEUE *pq)
{
    pq->front=pq->rear=-1;
}
void addq(QUEUE *pq,NODE *treenode)
{
    
    pq->data[++pq->rear]=treenode;
}

NODE * removeq(QUEUE *pq)
{
    return pq->data[++pq->front];
}

int isempty(QUEUE *pq)
{
    return(pq->rear==pq->front);
}

int isfull(QUEUE *pq)
{
    return(pq->rear == MAXSIZE-1);
}


// Tree functions
NODE * createbst(NODE *root)
{
    NODE *newnode, *temp,*parent;
    int i, n, num;
    printf("\n How many nodes:");
    scanf("%d",&n);
    printf("\n Enter the %d elements:",n);
    for(i=1;i<=n;i++)
    {
        newnode= (NODE *)malloc(sizeof(NODE));
        scanf("%d",&num);
        newnode->info=num;
        newnode->left=newnode->right=NULL;
        
        // attach new node in tree
        if(root == NULL)
        {
             root =newnode;
             continue;
        }
        temp =root;
        while(temp !=NULL)    // to find parent of new node Loop
        {
            parent =temp;
            if(num < temp->info)
                temp=temp->left;
            else
               temp=temp->right;
            
        }
        
         if( num < parent->info)   // attach node
             parent->left = newnode;
        else
             parent->right = newnode;
    }
return(root);
}

  
int levelorder(NODE *root)
{
    int i,level=0;
    NODE *temp,*marker=NULL;
    QUEUE q;
    initq(&q);
    addq(&q,root);
    addq(&q,marker);
    printf("\n Level %d ------>",level);
    
    
    while(!isempty(&q))
    {
        
        //level_count=0;
       
        temp = removeq(&q);
       
        if(temp==marker)
        {  
            level++;
            if(!isempty(&q))
            {
                addq(&q,marker);
                
                printf("\n Level %d ------>",level);
            }
            
         }
        else
        {
            printf("%d\t",temp->info);
            if(temp->left)
               addq(&q,temp->left);
            if(temp->right)
               addq(&q,temp->right);
         
        }
    }
    
    
    printf("\n Number of levels =%d",level);
    return level; 
}

int NodesAtLevel(NODE *root, int level)
{
        if(root==NULL)
                return 0;
        if(level==0)
               return 1;
        return NodesAtLevel(root->left,level-1) + NodesAtLevel(root->right,level-1);
}



/* OUTPUT:
How many nodes:5
 Enter the 5 elements:10 20 3 4 25
 Level 0 ------>10
 Level 1 ------>3       20
 Level 2 ------>4       25
 Number of levels =3
Number of nodes at [ 0 ] Level :: 1
Number of nodes at [ 1 ] Level :: 2
Number of nodes at [ 2 ] Level :: 2
*/