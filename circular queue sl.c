#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 5

struct CQUEUE
{
	int rear,front;
	int cq[max];
};

void create(struct CQUEUE *p)
{
	p->rear=-1;
	p->front=-1;
}

int isfull(struct CQUEUE *p)
{
	if(((p->front==0)&&(p->rear==max-1))||(p->front==p->rear+1))
	{
	return 1;
	}
	else
	{
	return 0;
	}
}

void insertion(struct CQUEUE *p)
{
	int item;
	printf("Enter the value:  ");
	scanf("%d",&item);
	if (p->front==-1)
	{
	p->front=0;
	p->rear=0;
	}
	else if(p->rear==max-1)
	{
	p->rear=0;
	}
	else
	{
	p->rear=p->rear+1;
	}
	p->cq[p->rear] = item;

}
void deletion(struct CQUEUE *p)
{

	int item;
	if(isempty(p))
	{
	printf("The queue underflow\n");
	return ;
	}
	item=p->cq[p->front];
	printf("The deleted item is :%d",item);
	if(p->front==p->rear)
	{
	p->front=-1;
	
	p->rear=-1;
	}
	else if(p->front==max-1 )
	p->front=0;
	else
	p->front=p->front+1;
}

void display(struct CQUEUE *p)
{
	int i;
	if(isempty(p))
	{
	printf("\n circular queue is empty");
	return ;
	}
	if(p->rear>=p->front)
	{
	for(i=p->front;i<=p->rear;i++)
	{
	printf("\nitems[%d]:%d",i,p->cq[i]);
	}
}

else
{
	for(i=p->front;i<max;i++)
	{
	printf("\nitems[%d]:%d",i,p->cq[i]);
	}
	for(i=0;i<=p->rear;i++)
	{
	printf("\nitems[%d]:%d",i,p->cq[i]);
	}
	}
}

int isempty(struct CQUEUE *p)
{
	if(p->front==-1)
	return 1;
	else
	return 0;
}

void main()
{

	struct CQUEUE q;
	int op;
	printf("1.insertion\n");
	printf("2.deletion\n");
	
	printf("3.display\n");
	printf("4.exit\n");
	create(&q);
do
{
	printf("Enter u r option\n");
	
	scanf("%d",&op);
	
	switch(op)
	{
	case 1:insertion(&q);break;
	case 2:deletion(&q);break;
	case 3:display(&q);break;
	case 4:exit(0);
}
}while(op<=4);

}
