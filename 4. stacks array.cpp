// STACKS USING ARRAY
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 5
int top=-1;
int arr[max];
void push(int ele)
{
	if(top==max-1)
	{
		printf("stack overflow \n");
		exit(0);
	}
	top++;
	arr[top]=ele;
}
void pop()
{
	if(top==-1)
	{
		printf("no elements stack underflow \n");
		exit(0);
	}
	printf("%d element deleted \n",arr[top--]);
}
void peek()
{
	if(top==-1)
	{
		printf("no elements stack underflow \n");
		exit(0);
	}
	printf("top element- %d\n",arr[top]);
}
void display()
{
	int i;
	printf("elements are- \n");
	for(i=top;i>-1;i--)
	{
		printf("%d\t",arr[i]);
	}
}
int main()
{
	int ele,a;
	while(1)
	{
		printf("\n-------------MENU---------------\n");
		printf("enter your choice- \n\n1. push \n2. pop \n3. peek \n4. display \n5. exit \n");
		scanf("%d",&a);
		printf("\n--------------------------------------------\n");
		switch(a)
		{
		case 1:printf("\nenter an element- \n");
			   scanf("%d",&ele);
			   push(ele);
		break;
		case 2:pop();
		break;
		case 3:peek();
		break;
		case 4:display();
		break;
		case 5:exit(0);
		default: printf("invalid choice\n");
		}	
	}
	return 0;
}
