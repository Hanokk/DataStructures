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
            		root->left->right=temp->left;
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
            		root->right->left=temp->right;
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

node *InorderSuccessor(node *current)
{
	if (current->left==NULL)
	{
		 return current;
	}
	else
	{
		current=InorderSuccessor(current->left);
	}
	return current;
}

node *Delete(node *root,int value)
{
    if (root->data==value)
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
                temp->left=root->left;
                temp->right=root->right;
                free(root);
                root=temp;
                root=Delete(root,temp->data);
           	}
        }
    }
    else
    {
        if (root->data>value)
        {
            root->left=Delete(root->left,value);
            node *temp;
            if (Height(root->left)-Height(root->right)==-2)
            {
            	int R=(Height(root->right->left)-Height(root->right->right));
            	if(R==0 || R==1) 
            	{
            		temp=root->right;
            		root->right=temp->left;
            		temp->left=root;
            		root=temp;
            	}
            	else if (R==-1)
            	{
            		temp=root->right->left;
            		root->right->left=temp->right;
            		temp->right=root->right;
            		root->right=temp->left;
            		temp->left=root;
            		root=temp;
            	}
            	else
            	{
            		printf("something's wrong\n");
            	}
            }
        }
        else
        {
            root->right=Delete(root->right,value);
            node *temp;
            if (Height(root->left)-Height(root->right)==2)
            {
            	int R=Height(root->left->left)-Height(root->left->right);
            	if(R==0 || R==1) 
            	{
            		temp=root->left;
            		root->left=temp->right;
            		temp->right=root;
            		root=temp;
            	}
            	else if (R==-1)
            	{
            		temp=root->left->right;
            		root->left->right=temp->left;
            		temp->left=root->left;
            		root->left=temp->right;
            		temp->right=root;
            		root=temp;
            	}
            	else
            	{
            		printf("something's wrong\n");
            	}
            }
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
        printf("%d\n",root->data);
        Print(root->right);
    }
}

int main(int argc, char const *argv[])
{
	node *root,*newnode;
	root=NULL;
	int option,value,height;
	while(1)
	{
		printf("Enter the operations\n1.Insert\n2.Delete\n3.Print\n4.Height\n5.Exit");
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
	            root=Insert(root,newnode);
				break;
			case 2:
				printf("Enter the value to be deleted\n");
				scanf("%d",&value);
				Delete(root,value);
				break;
			case 3:
				Print(root);
				break;
			case 4:
				height=Height(root);
				printf("%d\n",height);
				break;
			case 5:
				exit(0);
		}
	}
	return 0;
}
