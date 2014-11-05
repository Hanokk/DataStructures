#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct AVL
{
	int data;
	struct AVL *left;
	struct AVL *right;
};

typedef struct AVL node;

int Height(node *Head)
{
    int lheight=0,rheight=0;
	if(Head==NULL)
	{
		return 0;
	}
	lheight=Height(Head->left)+1;
	rheight=Height(Head->right)+1;
    if (lheight>rheight)
    {
        return lheight;
    }
    else
    {
	   return rheight;
    }
}

node *Insert(node *root,node *newnode)
{
    if (root==NULL)
    {
        root=newnode;

    }
    else
    {
        if (root->data>newnode->data)
        {
            root->left=Insert(root->left,newnode);
            if (Height(root->left)-Height(root->right)==2)
            {
            	node *temp;
            	if (newnode->data<root->left->data)
            	{
            		temp=root->left;
            		root->left=temp->right;
          			temp->right=root;
          			root=temp;
            	}
            	else
            	{
            		temp=root->left->right;
            		root->left=temp->left;
            		temp->left=root->left;
            		root->left=temp->right;
            		temp->right=root;
            		root=temp;
            	}
            }
        }
        else
        {
            root->right=Insert(root->right,newnode);
            if (Height(root->left)-Height(root->right)==-2)
            {
            	node *temp;
            	if (newnode->data>root->right->data)
            	{
            		temp=root->right;
            		root->right=temp->left;
          			temp->left=root;
          			root=temp;
            	}
            	else
            	{
            		temp=root->right->left;
            		root->right=temp->right;
            		temp->right=root->right;
            		root->right=temp->left;
            		temp->left=root;
            		root=temp;
            	}
            }
        }
    }
    return root;
}

node *Delete()
{

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
        printf("%d\t%d\n",root->data,root->weight);
        Print(root->right);
    }
}

int main(int argc, char const *argv[])
{
	node *root,*newnode;
	root=NULL;
	int option,value;
	while(1)
	{
		printf("Enter the operations\n1.Insert\n2.Delete\n3.Print");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			/*nbgvnmbhmjhjhvjhvhv*/
				printf("Enter the value\n");
	            scanf("%d",&value);
	            printf("\n");
	            newnode=(node *)malloc(sizeof(node));
	            newnode->data=value;
	            newnode->left=NULL;
	            newnode->right=NULL;
	            newnode->weight=0;
	            root=Insert(root,newnode);
				break;
			case 2:
				Delete();
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
