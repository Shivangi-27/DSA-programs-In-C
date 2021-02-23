#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct DLink
{
	struct DLink *prev;
	int info;
	struct DLink *next;
};
struct DLink *head,*ptr,*node;

void create()
{
	int c=0;
	char ch;
	do
	{
	node=(struct DLink*)malloc(sizeof(struct DLink));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	c++;
	node->next=NULL;
	node->prev=NULL;
	printf("\nenter the info %d \n",c);
	scanf("%d",&node->info);
	if(head==NULL)
	{
		head=node;
	}
	else
	{
		ptr->next=node;
		node->prev=ptr;
	}
	ptr=node;
	printf("do you want to continue press Y or y \n");
	ch=getche();
	}while(ch=='y'||ch=='Y');
}
void visit_forward()
{
	ptr=head;
	printf("\nelements are \n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
}
void visit_backward()
{
	ptr=head;
	while(ptr->next!=NULL)
	{
	ptr=ptr->next;
	}
	printf("\nelements are \n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->prev;
	} 
}
void count_node()
{
	int a=0;
	ptr=head;
	while(ptr!=NULL)
	{
		a++;
		ptr=ptr->next;
	}
	printf("\nno. of nodes are- %d\n",a);
}
void insert_beg()
{
	node=(struct DLink*)malloc(sizeof(struct DLink));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	node->next=NULL;
	node->prev=NULL;
	printf("\nenter the info at the beginning- \n");
	scanf("%d",&node->info);
	node->next=head;
	head->prev=node;
	head=node;
}
void insert_end()
{
	node=(struct DLink*)malloc(sizeof(struct DLink));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	node->next=NULL;
	node->prev=NULL;
	printf("\nenter the info at the end- \n");
	scanf("%d",&node->info);
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;		
	}
	ptr->next=node;
	node->prev=ptr;
	node->next=NULL;
}
void delete_beg()
{
	ptr=head;
	if(ptr==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	head=ptr->next;
	head->prev=NULL;
	free(ptr);
}
void delete_end()
{
	struct DLink *temp;
	ptr=head;
	if(ptr==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	while(ptr->next!=NULL)
	{
		temp=ptr;
		ptr=ptr->next;
	}
	temp->next=NULL;
	free(ptr);
}
int main()
{
	int a;
	while(1)
	{
		printf("\n-------------MENU---------------\n");
		printf("enter your choice- \n\n1. create a double linked list\n2. visit a double linked list forward\n3. visit a double linked list backward\n4. count no. of nodes of double linked list\n5. insert a node at beginning \n6. insert a node at end \n7. delete a node at beginning \n8. delete a node at end \n9. exit \n");
		scanf("%d",&a);
		printf("--------------------------------------------\n");
		switch(a)
		{
		case 1:create();
		break;
		case 2:visit_forward();
		break;
		case 3:visit_backward();
		break;
		case 4:count_node();
		break;
		case 5:insert_beg();
		break;
		case 6:insert_end();
		break;
		case 7:delete_beg();
		break;
		case 8:delete_end();
		break;
		case 9:exit(0);
		break;
		default: printf("invalid choice\n");
		}	
	}
	return 0;
}