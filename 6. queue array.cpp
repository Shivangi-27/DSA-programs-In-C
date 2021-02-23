// QUEUE USING ARRAY
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 5
int front=-1,rear=-1;
int arr[max];
void insert(int ele)
{
	if(rear==max-1)
	{
		printf("Q overflow \n");
		exit(0);
	}
	rear++;
	arr[rear]=ele;
	if(front==-1)
	front=0;
}
void delete_ele()
{
	if(front==-1)
	{
		printf("Q underflow \n");
		exit(0);
	}
	printf("%d element deleted \n",arr[front]);
	front++;
}
void peek()
{
	if(front==-1)
	{
		printf("Q underflow \n");
		exit(0);
	}
	printf("top element- %d\n",arr[front]);
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("Q underflow \n");
		exit(0);
	}
	printf("elements are- \n");
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int isfull()
{
	if(front==-1)
	return 1;	
	else
	return 0;
}
int isempty()
{
	if(front==max)
	return 1;	
	else
	return 0;	
}
int main()
{
	int ele,a;
	while(1)
	{
		printf("\n-------------MENU---------------\n");
		printf("enter your choice- \n\n1. insert \n2. delete \n3. peek \n4. display \n5. exit \n");
		scanf("%d",&a);
		printf("\n--------------------------------------------\n");
		switch(a)
		{
		case 1:printf("\nenter an element- \n");
			   scanf("%d",&ele);
			   insert(ele);
		break;
		case 2:delete_ele();
		break;
		case 3:peek();
		break;
		case 4:display();
		break;
		case 5:printf("Q is full",isfull());
		break;
		case 6:printf("Q is empty",isempty());
		break;
		case 7:exit(0);
		default: printf("invalid choice\n");
		}	
	}
	return 0;
}
