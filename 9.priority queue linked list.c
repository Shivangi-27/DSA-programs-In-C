#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
struct data
{
	char job[MAX];
	int p;
	int o;
	struct data *next;
};
struct data *front;

// create
void create_pq()
{
	static int j=0;
	struct data *node,*flag,*temp;
	node=(struct data*)malloc(sizeof(struct data));
	printf("enter the job and priority no. \n");
	scanf("%s %d",node->job, &node->p);
	node->o=j++;
	node->next=NULL;
	
	if(front==NULL)
	{
		front=node;
	}	
	
	else if(front->p > node->p)
	{
		node->next=front;
		front=node;
	}
	
	else
	{
		flag=front;
		while(flag->next!=NULL && flag->next->p <= temp->p)
		{
			flag=flag->next;
		}
			node->next=flag->next;
			flag->next=node;
			exit(0);
	}
}

// delete
void delete_pq()
{
	struct data *temp;
	if(front==NULL)
	{
		printf("PQ is empty or underflow\n");		
		exit(0);
	}	
	temp=front;
	front=front->next;
	temp->next=NULL;
	printf("%s %d %d block deleted \n",temp->job,temp->p,temp->o);
	free(temp);
}

// display
void display_pq()
{
	struct data *temp;
	if(front==NULL)
	{
		printf("PQ is empty or underflow\n");		
		exit(0);
	}	
	temp=front;
	printf("elements are\n");
	while(temp!=NULL)
	{
		printf("job- %s p- %d o- %d \n",temp->job,temp->p,temp->o);
		temp=temp->next;
	}
}

// peek
// display
void peek_pq()
{
	if(front==NULL)
	{
		printf("PQ is empty or underflow\n");		
		exit(0);
	}	
		printf("job- %s p- %d o- %d \n",front->job,front->p,front->o);
}
int main()
{
	int a;
	while(1)
	{
		printf("\n-------------MENU---------------\n");
		printf("enter your choice- \n\n1. create a PQ \n2. delete PQ \n3. display PQ \n4. peek PQ \n5. exit \n");
		scanf("%d",&a);
		printf("--------------------------------------------\n");
		switch(a)
		{
		case 1:create_pq();
		break;
		case 2:delete_pq();
		break;
		case 3:display_pq();
		break;
		case 4:peek_pq();
		break;
		case 5:exit(0);
		break;   
		default: printf("invalid choice\n");
		}	
	}
	return 0;
}
