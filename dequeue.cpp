#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 5

void input_dequeue();
void output_dequeue();
void insert_right(int);
void insert_left(int);
void delete_right();
void delete_left();
void display_dequeue();

int deque[max];
int left=-1,right=-1;
void main()
{

	int ch;
	printf("\n********Type Double ended queue*****\n");
	printf("\n 1.input_restricted deque \n");
	printf("2.output_restricted deque \n");
	printf("\nenter your choice of Queue Type :");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:input_dequeue();break;
		case 2:output_dequeue();break;
		default:printf("\n invalid operation");
	}
}

void input_dequeue()
{
	int ch1,no;
	char ch='y';
	while(ch=='y')
	{
		printf("\n\t1.insert in right");
		printf("\n\t2.delete from left");
		printf("\n\t3.delete from right");
		printf("\n\t4.display");
		printf("\n\tenter your option :");
		scanf("%d",&ch1);
		
	switch(ch1)
	{
		case 1:printf("enter a number ");
			   scanf("%d",&no);
			   insert_right(no);break;
		case 2:delete_left();break;
		case 3:delete_right();break;
		case 4:display_dequeue();break;
	}
	printf("\n\t do another operation(y/n)");
	ch=getche();
	}
}

void output_dequeue()
{
	int ch1,no;
	char ch='y';
	while(ch=='y')
	{
		printf("\n\t1.insert in right");
		printf("\n\t2.insert in left");
		printf("\n\t3.delete from left");
		printf("\n\t4.display");
		printf("\n\tenter your option :");
		scanf("%d",&ch1);
	switch(ch1)
	{
		case 1:printf("enter a number ");
		scanf("%d",&no);
		insert_right(no);
		break;
		case 2:printf("enter a number ");
		scanf("%d",&no);
		insert_left(no);
		break;
		case 3:delete_left();break;
		case 4:display_dequeue();break;
	}
	printf("\n\t do another operation(y/n)");
	ch=getche();
	}
}

void insert_right(int num)
{
	if((left==0&&right==max-1)||(left==right+1))
	{
		printf("\n deque overflow :");
		return;
	}
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else if(right==max-1)
		right=0;
	else
		right=right+1;
		deque[right]=num;
	}
void insert_left(int num)
{
	if((left==0&&right==max-1)||(left==right+1))
	{
		printf("\n deque overflow :");
		return;
	}
	if(left==-1)
	{
		left=0;
		right=0;
	}
	else if(left==0)
		left=max-1;
	else
		left=left-1;
		deque[left]=num;
}

void delete_left()
{
	int no;
	if(left==-1)
	{
	printf("\n\tunderflow");
	return ;
	}
	no=deque[left];
	if(left==right)
	{
	left=-1;
	right=-1;
	}
	else if(left==max-1)
	{
	left=0;
	}
	else
	{
	left=left+1;
	}
	printf("\n\t%d deleted ",no);
}
	
void delete_right()
{
	int no;
	if(left==-1)
	{
	printf("\n\tunderflow");
	return ;
	}
	no=deque[right];
	if(left==right)
	{
	left=-1;
	right=-1;
	}
	else if(right==0)
	{
	right=max-1;
	}
	else
	{
	right=right-1;
	}
	printf("\n\t%d deleted ",no);
}
	
void display_dequeue()
{
	int i;
	if(left<=right)
	{
		for(i=left;i<=right;i++)
		printf("%d ",deque[i]);
	}
	else
	{
		for(i=left;i<max;i++)
		printf("%d ",deque[i]);
		for(i=0;i<=right;i++)
		printf("%d ",deque[i]);
	}
}
