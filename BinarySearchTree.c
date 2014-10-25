#include<stdio.h>
#include<malloc.h>


void *pass(int *p)
{
	int c=1,*l;
	l=&c;
	return l;
}

void awesome(int k)
{
	printf("im awesome");
}

int main(int argc, char const *argv[])
{
	int *p=NULL,k=11;
	//p=(int *)malloc(sizeof(int));
	p=&k;
	printf("%d\n",*p);
	int *ptr=pass(p);
	awesome(k);
	printf("%d\n",*ptr);
	return 0;
}
