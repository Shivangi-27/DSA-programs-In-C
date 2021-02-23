#include <stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<ctype.h> 
#define size 100 
char stack[size]; 
int top=-1;
void push(char ch)
{
	if(top==size-1)
	{
		printf("stack overflow "); 
		return ;
	}
	top++;
	stack[top]=ch;
}

char pop()
{
	if(top==-1)
	{
		printf("stack underflow "); exit(0);
	}
	char item=stack[top]; 
	top--;
	return item;
}

int is_operator(char ch)
{
	switch(ch)
	{
	case '+':case'-':case '*': case '/': case '^':case '%' : return 1; 
	default :return 0;
	}
}

int precedence(char ch)
{
	if(ch=='^') 
	return 3;
	else if(ch=='*'||ch=='/'||ch=='%') 
	return 2;
	else if(ch=='+'||ch=='-') 
	return 1;
	else 
	return 0;
}

void infixtopostfix(char infix[],char postfix[])
{
	int i=0,j=0; 
	push('(');
	strcat(infix,")"); 
	char item=infix[i]; 
	char ch; while(item!='\0')
	{
	if(item=='(')	
	{
		push(item);
	}
	else if(isdigit(item)||isalpha(item))
	{
	postfix[j]=item; 
	j++;
	}
	else if(is_operator(item)==1)
	{
	ch=pop(); while(is_operator(ch)==1&&precedence(ch)>=precedence(item))
	{
	postfix[j]=ch; 
	j++;
	ch=pop();
	}
	push(ch); 
	push(item);
	}
	else if(item==')')
	{
	ch=pop(); 
	while(ch!='(')
	{
	postfix[j]=ch; 
	j++;
	ch=pop();
	}
	} 
	i++;
	item=infix[i];
	}
	postfix[j]='\0';
}
void main()
{
	char infix[size],postfix[size]; 
	printf("enter infix :	"); 
	gets(infix); 
	infixtopostfix(infix,postfix); 
	printf("post fix : "); 
	puts(postfix);
}
