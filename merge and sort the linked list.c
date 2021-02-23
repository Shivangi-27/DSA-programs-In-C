#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
struct Link
{
	int info;
	struct Link *next;
};
struct Link *head1,*head2,*ptr,*node;

void create(struct Link *head1)           
{
	int c=1;
	char ch;
	printf("\nenter the info %d \n",c);
	scanf("%d",&head1->info);
	head1->next=NULL;
	do
	{
	head1->next=(struct Link*)malloc(sizeof(struct Link));
	if(head1->next==NULL)
	{
		printf("no memory\n");
		return 0;
	}
	c++;
	head1=head1->next;
	printf("\nenter the info %d \n",c);
	scanf("%d",&head1->info);
	head1->next=NULL;
	printf("do you want to continue press Y or y \n");
	ch=getche();
	}while(ch=='y'||ch=='Y');
}

void visit(struct Link *head1)
{
	if(head1==NULL)
	{
		printf("no memory\n");
		return 0;
	}
	printf("\nelements are \n");
	while(head1!=NULL)
	{
		printf("%d\t",head1->info);
		head1=head1->next;
	}
}

void merge(struct Link *head1,struct Link *head2)           
{
	while(head1->next!=NULL)
	{
		head1=head1->next;
	}
	head1->next=head2;
}

void sort(struct Link *head1)
{
	struct Link *node;
	int  temp;
	ptr=head1;
	while(ptr->next!=NULL)
	{
		node=ptr->next;
		while(node!=NULL)
		{
			if(ptr->info > node->info)
			{
				temp=ptr->info;
				ptr->info=node->info;
				node->info=temp;
			}
			node=node->next;
		}
		ptr=ptr->next;
	}
}

int main()
{
	struct Link *head1=(struct Link*)malloc(sizeof(struct Link));
	if(head1==NULL)
	{
		printf("no memory\n");
		return 0;
	}
	printf("1st linked list\n");
	create(head1);
	visit(head1);
	
	struct Link *head2=(struct Link*)malloc(sizeof(struct Link));
	if(head2==NULL)
	{
		printf("no memory\n");
		return 0;
	}
	printf("2nd linked list\n");
	create(head2);
	visit(head2);
	
	printf("\nmerged linked list\n");
	merge(head1,head2);
	visit(head1);
	
	printf("\nsorted and merged linked list\n");
	sort(head1);
	visit(head1);
	return 0;
}

