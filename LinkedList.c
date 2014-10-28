#include<stdio.h>
#include<malloc.h>

struct Linkedlist
{
	int data;
	struct Linkedlist *next;

};

typedef struct Linkedlist node;

node *InsertAtBegin(node *Head)
{
	newnode=Newnode();
	newnode->next=Head;
	Head=newnode;
	return Head;
}

node *InsertAtEnd(node *Head)
{	
	if (Head->next=NULL)
	{
		newnode=Newnode();
		Head->next=newnode;
	}
	else
	{
		Head=InsertAtEnd(Head);
	}
	return Head;
}

node *InsertAt(node *Head,int value)
{
	if (Head->data==value)
	{
		newnode=Newnode();
		newnode->next=Head->next;
		Head->next=newnode;
	}
	else
	{
		Head=InsertAt(Head,value);
	}
	return Head;
}

node *Delete(node *Head,int value)
{
	if (Head->data==value)
	{
		
	}
}

node *Newnode()
{
	node *newnode;
	newnode=(node *)malloc(sizeof(node));
	printf("Enter the data to be inserted\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}
int main(int argc, char const *argv[])
{
	Head=(node *)malloc(sizeof(node));
	int option;
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
			Head=InsertAt(Head,value);
			break;
		case 4:
			printf("Enter the number to be deleted\n");
			scanf("%d",&value);
			Head=Delete(Head,value);
			break;
		case 5:
			Head=Print(Head);
			break;
	}

	return 0;
}