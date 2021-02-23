// Single linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Link
{
	int info;
	struct Link *next;
};
struct Link *head,*ptr,*node;

//create
void create()           
{
	int c=0;
	char ch;
	do
	{
	node=(struct Link*)malloc(sizeof(struct Link));
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
	}
	ptr=node;
	printf("do you want to continue press Y or y \n");
	ch=getche();
	}while(ch=='y'||ch=='Y');
}

//visit
void visit()
{
	ptr=head;
	printf("\nelements are \n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
}

//count node
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

//insert begin
void insert_beg()
{
	node=(struct Link*)malloc(sizeof(struct Link));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	node->next=NULL;
	printf("\nenter the info at the beginning- \n");
	scanf("%d",&node->info);
	node->next=head;
	head=node;
}

//insert end
void insert_end()
{
	node=(struct Link*)malloc(sizeof(struct Link));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	node->next=NULL;
	printf("\nenter the info at the end- \n");
	scanf("%d",&node->info);
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;		
	}
	ptr->next=node;
}

//delete begin
void delete_beg()
{
	ptr=head;
	if(ptr==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	head=ptr->next;
	free(ptr);
}

//delete end
void delete_end()
{
	struct Link *temp;
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

//sum of the elements
void sum()
{
	int s=0;
	ptr=head;
	while(ptr!=NULL)
	{
		s=s+ptr->info;
		ptr=ptr->next;
	}
	printf("sum= %d",s);
}

//biggest element
void biggest_element()
{
	int big;
	big=head->info;
	ptr=head;
	while(ptr->next!=NULL)
	{
		if(big<ptr->info)
		{
			big=ptr->info;
		}
		ptr=ptr->next;
	}
	printf("biggest element= %d",big);
}

//count and display even elements 
void even_element()
{
	int e=0;
	ptr=head;
	printf("even elements are \n");
	while(ptr!=NULL)
	{
		if(ptr->info%2==0)
		{
			printf("%d\t",ptr->info);
			e++;
		}
		ptr=ptr->next;
	}
	printf("\nno. of even elements is= %d \n",e);
}

//count and display odd elements
void odd_element()
{
	int o=0;
	ptr=head;
	printf("odd elements are \n");
	while(ptr!=NULL)
	{
		if(ptr->info%2!=0)
		{
			printf("%d\t",ptr->info);
			o++;
		}
		ptr=ptr->next;
	}
	printf("\nno. of odd elements is= %d \n",o);
}

//insert after node
void insert_after_node()
{
	int ser;
	printf("\nenter an element for search- \n");
	scanf("%d",&ser);
	ptr=head;
	if(ptr!=NULL && ptr->info!=ser)	
	{
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("%d element not found \n",ser);
		exit(0);
	}
	node=(struct Link*)malloc(sizeof(struct Link));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	printf("\nenter the info- \n");
	scanf("%d",&node->info);
/*	if(ptr->next==NULL)
	{
		ptr->next=node;
		node->next=NULL;
		exit(0);
	}  */
	node->next=ptr->next;
	ptr->next=node;	
}

//insert position
void insert_position()
{
	int i=1,pos;
	printf("\nenter a position to  insert- \n");
	scanf("%d",&pos);
	node=(struct Link*)malloc(sizeof(struct Link));
	if(node==NULL)
	{
		printf("no memory\n");
		exit(0);
	}
	ptr=head;
	if(pos==1)	
	{
		node->next=head;
		head=node;
		exit(0);
	}
	if(ptr!=NULL && i<pos-1)	
	{
		ptr=ptr->next;
		i++;
	}
	if(ptr==NULL)
	{
		printf("%d pos not found \n",pos);
		exit(0);
	}
	printf("\nenter the info- \n");
	scanf("%d",&node->info);
	node->next=ptr->next;
	ptr->next=node;	
}

//delete after node
void delete_after_node()
{
	int ser;
	struct Link *temp;
	printf("\nenter an element for search- \n");
	scanf("%d",&ser);
	ptr=head;
	while(ptr!=NULL && ptr->info!=ser)	
	{
		temp=ptr;
		ptr=ptr->next;
	}
	if(ptr->next==NULL)
	{
		printf("%d element not found \n",ser);
		exit(0);
	}
	temp->next=ptr->next;	
	free(ptr);
}

//delete position
void delete_position()
{
	struct Link *temp;
	int i=1,pos;
	printf("\nenter a position to  delete- \n");
	scanf("%d",&pos);
	ptr=head;
	if(pos==1)	
	{
		head=head->next;
		free(ptr);
		exit(0);
	}
	ptr=head;
	while(ptr!=NULL && i<pos)	
	{
		temp=ptr;
		ptr=ptr->next;
		i++;
	}
	if(ptr==NULL)
	{
		printf("%d pos not found \n",pos);
		exit(0);
	}
	temp->next=ptr->next;
	ptr->next==NULL;
	free(ptr);
}  
int main()
{
	int a;
	while(1)
	{
		printf("\n-------------MENU---------------\n");
		printf("enter your choice- \n\n1. create a single linked list\n2. visit a single linked list\n3. count no. of nodes of single linked list\n4. insert a node at beginning \n5. insert a node at end \n6. delete a node at beginning \n7. delete a node at end \n8. sum of the elements \n\n9. biggest element \n\n10. count and display even elements \n11. count and display odd elements \n12. insert after node \n13. insert at specific position \n14. delete after node \n15. delete at specific position  \n16. exit \n");
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
		case 8:sum();
		break;
		case 9:biggest_element();
		break;
		case 10:even_element();
		break; 
		case 11:odd_element();
		break;
		case 12:insert_after_node();
		break;
		case 13:insert_position();
		break;
		case 14:delete_after_node();
		break;
		case 15:delete_position();
		break;
		case 16:exit(0);
		break;
		default: printf("invalid choice\n");
		}	
	}
	return 0;
}
