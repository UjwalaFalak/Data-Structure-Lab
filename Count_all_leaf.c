//.c File	
#include<stdio.h>
#include<stdlib.h>
#include “btree_b.h”
int main()
{
	int cleaf=0,Tcnt=1;
   NODE root=NULL;
	root=createbst(root);
   Cleaf=countleaf(root);
   Tcnt=coundnodes(root);
Printf(“Total number of nodes from BST are %d”,Tcnt);
Printf(“Total number of leaf nodes from BST are %d”,cleaf);
return 0;
}


//btree_c.h
typedef struct node
{
	int info;
	struct node *left, *right;
}NODE;
NODE * createbst(NODE *root)
{
	NODE *newnode, *temp,*parent;
	int i, n, num;
	printf("\n How many nodes:");
	scanf("%d",&n);
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
    	while(temp !=NULL)	// to find parent of new node Loop
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
Int countnodes(NODE * root)
{
        	 Static int count=0;
	    	NODE *temp=root;
If(temp!=NULL)
{
                    	Count++;
                    	Countnodes(temp->left);
                    	Countnodes(temp->right);
}
Return count;
}
int countleaf(NODE * root)
{
        	Static int leaf=0;
        	NODE *temp=root;
        	If(temp!=NULL)
        	{
                    	If((temp->left==NULL) && (temp->right==NULL))
                    	Leaf++;
                    	Counfleaf(temp->left);
                    	Counfleaf(temp->right);
        	}
        	Return leaf;
}


