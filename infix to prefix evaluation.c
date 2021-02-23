#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
#include<conio.h>
#include<ctype.h> 
#define size 20 
int stack[size]; 
int top=-1;
void push(int item)
{
	if(top==size-1)
	{
		printf("stack overflow "); 
		return ;
	}
	top++;
	stack[top]=item;
}

char pop()
{
	int item;
	if(top==-1)
	{
		printf("stack underflow "); 
		exit(0);
	}
	item=stack[top]; 
	top--;
	return item;
}

void evalpreexp(char pre[])
{
	int a,b,val,data=-1,i;
	char ch;
	for(i=0;pre[i]!=')';i++)
	{
		ch=pre[i];
		if(isdigit(ch))
		{
			data=(data=-1)?0:data;
			data=data*10+(ch-'0');
			continue;
		}
		if(data!=-1)
		{
			push(data);
		}
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		{
		a=pop();
		b=pop();
		switch(ch)
		{
			case'+':val=b+a;break;
			case'-':val=b-a;break;
			case'*':val=b*a;break;
			case'/':val=b/a;break;
		}
		push(val);
		}
		data=-1;
	}
printf("result is= %d",pop());
}
int main()
{
	char pre[size];
	int i;
	printf("enter infix exp- \n");
	for(i=0;i<=size-1;i++)
	{
		scanf("%d",&pre[i]);
		if(pre[i]==')')
		{
			break;
		}
	}
	evalpreexp(strrev(pre));
return 0;	
}
