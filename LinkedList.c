#include<stdio.h>
#include<malloc.h>

struct Linkedlist
{
	int data;
	struct Linkedlist *next;

};

typedef struct Linkedlist node;

node *Newnode()
{
	node *newnode;
	newnode=(node *)malloc(sizeof(node));
	printf("Enter the data to be inserted\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}

node *InsertAtBegin(node *Head)
{
	node *newnode;
	newnode=Newnode();
	newnode->next=Head;
	Head=newnode;
	return Head;
}

node *InsertAtEnd(node *Head)
{	
	if (!Head)
	{
		printf("Empty\n");
		return 0;
	}
	if (Head->next==NULL)
	{
		node *newnode;
		newnode=Newnode();
		Head->next=newnode;
		return Head;
	}
	else
	{
		Head->next=InsertAtEnd(Head->next);
	}
	return Head;
}

node *InsertAt(node *Head,int value)
{
	if (!Head)
	{
		printf("Not Found\n");
		return 0;
	}
	if (Head->data==value)
	{
		node *newnode;
		newnode=Newnode();
		newnode->next=Head->next;
		Head->next=newnode;
	}
	else
	{
		Head->next=InsertAt(Head->next,value);
	}
	return Head;
}

node *Delete(node *Head,int value)
{
	if(!Head)
	{
		printf("Not Found\n");
		return Head;
	}
	else if (Head->data==value)
	{
		node *temp;
		temp=Head->next;
		free(Head);
		return temp;
	}
	else
	{
		Head->next=Delete(Head->next,value);
	}
	return Head;
}

node Print(node *Head)
{
	if(!Head)
	{
		printf("Empty\n");
	}
	else
	{
		while(Head)
		{
			printf("%d\n",Head->data);
			Head=Head->next;
		}
	}
}


int main(int argc, char const *argv[])
{
	node *Head;
	Head=NULL;
	int option;
	while(true)
	{
		printf("Choose the operation\n1.Insert at the begining\n2.Insert at the end\n3.Insert after a value\n4.Delete\n5.Print\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				Head=InsertAtBegin(Head);
				break;
			case 2:
				Head=InsertAtEnd(Head);
				break;
			case 3:
				int value;
				printf("Enter the value to insert after\n");
				scanf("%d",&value);
				if (!Head)
				{
					printf("empty\n");
					return 0;
				}
				Head=InsertAt(Head,value);
				break;
			case 4:
				if (!Head)
				{
					printf("Empty\n");
					return 0;
				}
				else
				{
					printf("Enter the number to be deleted\n");
					scanf("%d",&value);
					Head=Delete(Head,value);
					break;
				}
			case 5:
				Print(Head);
				break;
		}
	}
	return 0;
}