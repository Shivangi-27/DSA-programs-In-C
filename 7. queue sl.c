// QUEUE USING SINGLE LINKED LIST
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queue
{
	int info;
	struct queue *next;
};
struct queue *front=NULL,*rear=NULL,*temp;
void insert(int ele)
{
	struct queue *node;
	node=(struct queue *)malloc(sizeof(struct queue));
	if(node==NULL)
	{
		printf("Q overflow \n");
		exit(0);
	}
	node->info=ele;
	node->next=NULL;
	if(front==NULL)
		front=rear=node;
	else
	{
		rear->next=node;
	    rear=node;	
	}	
}
void delete_ele()
{
	if(front==NULL)
	{
		printf("Q underflow \n");
		exit(0);
	}
	printf("%d element deleted \n",front->info);
	temp=front;
	front=front->next;
	free(temp);
}
void peek()
{
	if(front==NULL)
	{
		printf("Q underflow \n");
		exit(0);
	}
	printf("top element- %d\n",front->info);
}
void display()
{
	temp=front;
	printf("elements are- \n");
	while(temp->next!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}
	printf("%d\t",temp->info);
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
			   insert(ele);;
		break;
		case 2:delete_ele();
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
