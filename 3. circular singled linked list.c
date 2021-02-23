// CIRCULAR LINKED LIST
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct CLink
{
	int info;
	struct CLink *next;
};
struct CLink *head,*ptr,*node;
void create()
{
	int c=0;
	char ch;
	do
	{
	node=(struct CLink*)malloc(sizeof(struct CLink));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	c++;
	node->next=NULL;
	printf("\nenter the info %d \n",c);
	scanf("%d",&node->info);
	if(head==NULL)
	{
		head=node;
	}
	else
	{
		ptr->next=node;
		node->next=head;
	}
	ptr=node;
	printf("do you want to continue press Y or y \n");
	ch=getche();
	}while(ch=='y'||ch=='Y');
}
void visit()
{
	ptr=head;
	printf("\nelements are \n");
	do
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}while(ptr!=head);
}
void count_node()
{
	int a=0;
	ptr=head;
	do
	{
		a++;
		ptr=ptr->next;
	}while(ptr!=head);
	printf("\nno. of nodes are- %d\n",a);
}
void insert_beg()
{
	node=(struct CLink*)malloc(sizeof(struct CLink));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	node->next=NULL;
	printf("\nenter the info at the beginning- \n");
	scanf("%d",&node->info);
	do
	{
		ptr=ptr->next;		
	}while(ptr->next!=head);
	ptr->next=node;
	node->next=head;
	head=node;
}
void insert_end()
{
	node=(struct CLink*)malloc(sizeof(struct CLink));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	node->next=NULL;
	printf("\nenter the info at the end- \n");
	scanf("%d",&node->info);
	ptr=head;
	do
	{
		ptr=ptr->next;		
	}while(ptr->next!=head);
	ptr->next=node;
	node->next=head;
}
void delete_beg()
{
	struct CLink *temp;
	ptr=head;
	if(ptr==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	do
	{
		ptr=ptr->next;		
	}while(ptr->next!=head);
	temp=head;
	ptr->next=head->next;
	head=ptr->next;
	free(temp);
}
void delete_end()
{
	struct CLink *temp;
	ptr=head;
	if(ptr==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	do
	{
		temp=ptr;
		ptr=ptr->next;		
	}while(ptr->next!=head);	
	temp->next=head;
	free(ptr);
}
int main()
{
	int a;
	while(1)
	{
		printf("\n-------------MENU---------------\n");
		printf("enter your choice- \n\n1. create a circular linked list\n2. visit a circular linked list\n3. count no. of nodes of circular linked list\n4. insert a node at beginning \n5. insert a node at end \n6. delete a node at beginning \n7. delete a node at end \n8. exit \n");
		scanf("%d",&a);
		printf("--------------------------------------------");
		switch(a)
		{
		case 1:create();
		break;
		case 2:visit();
		break;
		case 3:count_node();
		break;
		case 4:insert_beg();
		break;
		case 5:insert_end();
		break;
		case 6:delete_beg();
		break;
		case 7:delete_end();
		break;
		case 8:exit(0);
		break;    
		default: printf("invalid choice\n");
		}	
	}
	return 0;
}
