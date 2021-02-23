#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Max 5

int rear=-1;
int front=-1;
int cq[Max];
void insertion()
{
	int item;
	printf("Enter the value:  ");
	scanf("%d",&item);
	if (front==-1)
	{
	front=0;
	rear=0;
	}
	else if(rear==Max-1)
	{
		rear=0;
	}
	else
	{
		rear=rear+1;
	}
	cq[rear] = item;
}
void deletion()
{
	int item;
	item=cq[front];
	printf("The deleted item is :%d",item);
	if(front==rear)
	{
		front=-1;
	rear=-1;
	}
	else if(front==Max-1 )
	front=0;
	else
	front=front+1;
}
void display()
{
	int i;
	if(rear>=front)
	{
	for(i=front;i<=rear;i++)
		{
			printf("\nitems[%d]:%d",i,cq[i]);
		}
	}
	else
	{
	for(i=front;i<Max;i++)
		{
			printf("\nitems[%d]:%d",i,cq[i]);
		}
	for(i=0;i<=rear;i++)
		{
			printf("\nitems[%d]:%d",i,cq[i]);
		}
	}
}
int isfull()
{
	if(((front==0)&&(rear==Max-1))||(front==rear+1))
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
int isempty()
{
	if(front==-1)
	return 1;
	else
	return 0;
}

int main()
{
	int op;
	printf("1.insertion\n");
	printf("2.deletion\n");
	printf("3.display\n");
	printf("4.exit\n");
	do
	{
		printf("Enter u r option\n");
		scanf("%d",&op);
	switch(op)
		{
			case 1:insertion();
			break;
			case 2:deletion();
			break;
			case 3:display();
			break;
			case 4:exit(0);
		}
	}while(op<=4);
	return 0;
}
