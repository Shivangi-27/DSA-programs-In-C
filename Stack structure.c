#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 5

struct stack
{
	int st[MAX];
	int top;
}s;

void push(int ele)
{
	if(s.top==(MAX-1))
	{
		printf("Stack overflow \n");
		return 0;
	}
	else
	{
		s.top=s.top+1;
		s.st[s.top]=ele;
	}
}

void pop()
{
	if(s.top==-1)
	{
		printf("Stack underflow \n");
		return 0;
	}
	else
	{
		printf("%d element popped \n", s.st[s.top]);
		s.top=s.top-1;
	}
}

void peek()
{
	if(s.top==-1)
	{
		printf("Stack underflow \n");
		return 0;
	}
	else
	{
		printf("%d\n", s.st[s.top]);
	}
}

void display()
{
	int i;
	if(s.top==-1)
	{
		printf("Stack underflow \n");
		return 0;
	}
	else
	{
		for(i=0;i<=MAX-1;i++)
		{
			printf("%d\t", s.st[i]);
		}
	}
}

int main()
{
	int ele,a;
	s.top=-1;
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
