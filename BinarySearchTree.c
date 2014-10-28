#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct tree
{
    int value;
    struct tree *left,*right;
};

typedef struct tree node;

void *Insert(node *root,node *newnode)
{
    if (root==NULL)
    {
        root=newnode;
    }
    else
    {
        if (root->value>newnode->value)
        {
            root->left=Insert(root->left,newnode);
        }
        else
        {
            root->right=Insert(root->right,newnode);
        }
    }
    return root;
}

void Print(node *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        Print(root->left);
        printf("%d\n",root->value);
        Print(root->right);
    }
}

node *InorderSuccessor(node *current)
{
	if (current->left==NULL)
	{
		printf("Hola\n");
		 return current;
	}
	else
	{
		current=InorderSuccessor(current->left);
	}
	return current;
}

node *Delete(node *root,int val)
{
    if (root->value==val)
    {
        if (root->left==NULL)
        {
            if (root->right==NULL)
            {
            	free(root);
                root=NULL;
            }
            else
            {
             	root=root->right;   
            }
        }
        else
        {
        	if (root->right->left==NULL)
        	{
        		root->right->left=root->left;
        		root=root->right;
        	}
        		else
       		{
        		node *temp;
 	           	temp=InorderSuccessor(root->right);
 	           	printf("hey");
                temp->left=root->left;
                temp->right=root->right;
                free(root);
                root=temp;
                root=Delete(root,temp->value);
           	}
        }
    }
    else
    {
        if (root->value>val)
        {
            root->left=Delete(root->left,val);
        }
        else
        {
            root->right=Delete(root->right,val);
        }
    }
    return root;
}

int main()
{
    int n,val;
    node *root;
    node *newnode;
    root=NULL;
    while(1)
    {
    printf("Take any operation\n1.Insert\n2.Delete\n3.Print\n4.Exit");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("Enter the value\n");
            scanf("%d",&val);
            printf("\n");
            newnode=(node *)malloc(sizeof(node));
            newnode->value=val;
            newnode->left=NULL;
            newnode->right=NULL;
            root=Insert(root,newnode);
            Print(root);
            break;

        case 2:
            printf("Enter the number to be deleted\n");
            scanf("%d",&val);
            root=Delete(root,val);
            break;

        case 3:
            Print(root);
            break;

        case 4:
            exit(0);
    }
    }
    return 0;
}