// STACKS USING SINGLE LINKED LIST
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Stack
{
	int info;
	struct Stack *next;
};
struct Stack *top=NULL;
void push(int ele)
{
	struct Stack *node;
	node=(struct Stack *)malloc(sizeof(struct Stack));
	if(node==NULL)
	{
		printf("stack overflow \n");
		exit(0);
	}
	node->info=ele;
	node->next=top;
	top=node;
}
void pop()
{
	struct Stack *temp=top;
	if(top==NULL)
	{
		printf("no elements stack underflow \n");
		exit(0);
	}	
	top=top->next;
	printf("%d element deleted \n",temp->info);
	free(temp);
}
void peek()
{
	if(top==NULL)
	{
		printf("no elements stack underflow \n");
		exit(0);
	}
	printf("top element- %d\n",top->info);
}
void display()
{
	if(top==NULL)
	{
		printf("no elements stack underflow \n");
		exit(0);
	}
	struct Stack *temp=top;
	printf("elements are- \n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
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
