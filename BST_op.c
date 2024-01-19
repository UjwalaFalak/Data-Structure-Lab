#include<stdio.h>
#include<stdlib.h>
#include "SetA_btree_a.h"
int main()
{
    int val,key,choice;
    NODE *root = NULL;
    do
    {
      printf("\n MENU");
      printf("\n 1. Create");
      printf("\n 2. Insert");
      printf("\n 3. Preorder Traversal");
      printf("\n 4. Inorder Traversal");
      printf("\n 5. Postorder Traversal");
      printf("\n 6. Search ");
      printf("\n Enter your choice");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
                root = createbst(root);    // Create
                break;
        case 2:
                // Insert new node in BST
                printf("\n Enter the node value to be inserted:");
                scanf("%d",&val);
                root=insertbst(root,val);
                break;
        case 3:
            // Traverse
            printf("\n The Preorder traversal is :");
            preorder(root);
            break;
        case 4:
            // Traverse
             printf("\n The Inorder traversal is :");
             inorder(root); 
             break;
       case 5:
            // Traverse
            printf("\n The Postorder traversal is :");
            postorder(root);
            break;
        case 6 : // search 
            printf("\n Enter the node value to be searched:");
            scanf("%d",&key);
            root=search(root, key);
            break;
      }
    }while(choice!=7);
return 0;
}


// SetA_btree_a.h

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


// Insert 
NODE *insertbst(NODE *root, int val)
{
    NODE *newnode, *temp=root, *parent;
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->info = val;
    newnode->left = newnode->right =NULL;
    // attach new node in tree
        if(root == NULL)
        {
             root =newnode;
             return root;
        }
       
        while(temp !=NULL)    // to find parent of new node Loop
        {
            parent =temp;
            if(val < temp->info)
                temp=temp->left;
            else
               temp=temp->right;
            
        }
        
         if( val < parent->info)   // attach node
             parent->left = newnode;
        else
             parent->right = newnode;
    
return(root);
}

NODE* search(NODE *root, int data)
{
    if(root == NULL)
       printf("\nElement not found");
    else if(data < root->info)
    {
       root->left=search(root->left, data);
    }
   else if(data > root->info)
   {
      root->right=search(root->right, data);
   }
   else
    printf("\nElement found is: %d", root->info);
	return root;
}
  
// Preorder    D L R
void preorder(NODE * root)
{
    NODE *temp =root;
    if(temp != NULL)
    {
        printf("%d\t",temp->info);    // DAta
        preorder(temp->left);  // left
        preorder(temp->right);   //right
    }
}

// Inorder  L D R
void inorder(NODE * root)
{
    NODE *temp =root;
    if(temp != NULL)
    {
        inorder(temp->left);  // left
        printf("%d\t",temp->info);    // DAta
        inorder(temp->right);   //right
    }
}

// Postorder  L  R  D
void postorder(NODE * root)
{
    NODE *temp =root;
    if(temp != NULL)
    {
        postorder(temp->left);  // left
        postorder(temp->right);   //right
        printf("%d\t",temp->info);    // DAta
        
    }
}

