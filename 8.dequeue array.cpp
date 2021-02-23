#include<stdio.h>
#include<conio.h>
#define max 5
int arr[max];
int front=-1,rear=-1;
void insert_right(int ele)
{
	if((front==0 && rear==max-1)||(front==rear+1))
	{
		printf("DQ overflow");
		exit(0);
	}
	if(front==-1)
	{
		front=rear=0;
	}
	else if(rear==max-1)
	{
		rear=0;
	}
	else
	{
		rear++;
	}
	arr[rear]=ele;
}
void insert_left(int ele)
{
	if((front==0 && rear==max-1)||(front==rear+1))
	{
		printf("DQ overflow");
		exit(0);
	}
	if(front==-1)
	{
		front=rear=0;
	}
	else if(front==0)
	{
		front=max-1;
	}
	else
	{
		front--;
	}
	arr[front]=ele;
}
void delete_right()
{
	if(front==-1)
	{
		printf("DQ underflow");
		exit(0);
	}
	printf("%d element deleted", arr[rear]);
	if(front==rear)
	{
		front=rear=-1;
	}
	else if(rear==0)
	{
		rear=max-1;
	}
	else
	{
		rear--;
	}
}
void delete_left()
{
	if(front==-1)
	{
		printf("DQ underflow");
		exit(0);
	}
	printf("%d element deleted", arr[front]);
	if(front==rear)
	{
		front=rear=-1;
	}
	else if(front==max-1)
	{
		front=0;
	}
	else
	{
		front++;
	}
}
