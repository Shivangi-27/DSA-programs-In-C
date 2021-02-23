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
void insert_afternode()
{
	int ser;
	struct CLink *temp;
	node=(struct CLink*)malloc(sizeof(struct CLink));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	node->next=NULL;
	printf("\nenter the info- \n");
	scanf("%d",&node->info);
	printf("\nenter the search element - \n");
	scanf("%d",&ser);	
	ptr=head;
	do
	{
		temp=ptr;
		ptr=ptr->next;		
	}while(temp->next!=head && temp->info!=ser);
	if(ptr==head)
	{
		printf("\n%d element not found \n",ser);
	}    
	node->next=ptr;
	temp->next=node;	
}
void insert_position()
{
	int i=1,pos;
	struct CLink *temp;
	node=(struct CLink*)malloc(sizeof(struct CLink));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	node->next=NULL;
	printf("\nenter the info- \n");
	scanf("%d",&node->info);
	printf("\nenter the pos - \n");
	scanf("%d",&pos);	
	ptr=head;
	if(pos==i)
	{
		do
	{
		temp=ptr;
		ptr=ptr->next;		
	}while(ptr!=head);
	node->next=ptr;
	temp->next=node;
	head=node;
	}  
	while(ptr->next!=head && i<pos-1)
	{
		temp=ptr;
		ptr=ptr->next;
		i++;		
	}
	node->next=ptr->next;
	ptr->next=node;
	if(ptr==head)
	{
		printf("\n%d position not found \n",pos);
	}    	
}
void delete_afternode()
{
	int ser;
	struct CLink *temp;
	printf("\nenter the search element - \n");
	scanf("%d",&ser);	
	ptr=head;
	do
	{
		temp=ptr;
		ptr=ptr->next;		
	}while(temp->next!=head && temp->info!=ser);
	if(ptr==head)
	{
		printf("\n%d element not found \n",ser);
	}  
	if(ptr->next==head)
	{
		temp->next==head;
		free(ptr);	
	}  
	temp->next=ptr->next;	
	free(ptr);	
}
void delete_position()
{
	int i=1,pos;
	struct CLink *temp;
	printf("\nenter the pos - \n");
	scanf("%d",&pos);	
	ptr=head;
	if(pos==i)
	{
		do
	{
		temp=ptr;
		ptr=ptr->next;		
	}while(ptr!=head);
	temp->next=head->next;
	head=temp->next;
	free(ptr);
	}  
	while(ptr->next!=head && i<pos)
	{
		temp=ptr;
		ptr=ptr->next;
		i++;		
	}
	if(ptr==head)
	{
		printf("\n%d position not found \n",pos);
	}    
	temp->next=ptr->next;
	free(ptr);
}  
int main()
{
	int a;
	while(1)
	{
		printf("\n-------------MENU---------------\n");
		printf("enter your choice- \n\n1. create a circular linked list\n2. visit a circular linked list\n3. count no. of nodes of circular linked list\n4. insert after given node \n5. insert at position \n6. delete after given node \n7. delete at position \n8. exit \n");
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
		case 4:insert_afternode();
		break;
		case 5:insert_position();
		break;
		case 6:delete_afternode();
		break;
		case 7:delete_position();
		break;    
		case 8:exit(0);
		break;    
		default: printf("invalid choice\n");
		}	
	}
	return 0;
}
