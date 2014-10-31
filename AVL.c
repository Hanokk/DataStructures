#include<stdio.h>
#include<malloc.h>

struct AVL
{
	int data;
	struct AVL *left;
	struct AVL *right;
	int weight;
};

typedef struct AVL node;

node *Insert()
{

}

node *Delete()
{

}

void Print()
{

}

int main(int argc, char const *argv[])
{
	node *Head;
	Head=NULL;
	int option;
	printf("Enter the operations\n1.Insert\n2.Delete\n3.Print");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			Insert();
			break;
		case 2:
			Delete();
			break;
		case 3:
			Print();
			break;
	}
	return 0;
}
