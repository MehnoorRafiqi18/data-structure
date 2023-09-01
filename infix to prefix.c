//infix to prefix
#include<stdio.h>
#include<math.h>
#include<string.h>

char stack[100];
char pre[100];
int top=-1;

void push(char item)
{
	stack[++top]=item;
}

int operand(char item)
{
	if(item=='+' || item=='-' || item=='*' || item=='/' || item=='^' || item=='%' )
		return 0;
	else
		return 1;
}

int priority(char x)
{
	if(x=='^')
		return 3;
	else if(x=='*' || x=='/')
		return 2;
	else if(x=='+' || x=='-')
		return 1;
	else
		return 0;
}

char pop()
{
	return stack[top--];
}

int main()
{
	char expr[100];
	printf("enter infix expression with proper spaces between operands and operators: ");
	gets(expr);
	push('(');
	int i=strlen(expr)-1,j=0;
	while(i>=0)
	{
		
		char x=expr[i];
		if(x==' ')
		{
			i--;
			continue;
		}
		
		else if(x==')')
		{
			push(x);
		}
		
		else if(x=='(')
		{
			while(stack[top]!=')')
			{
				char item = pop();
				pre[j++]=item;	
			}	
			pop();
			
		}
		else if(operand(x)==1)
		{
			pre[j++]=x;
		}
		else
		{
			while(priority(x)<priority(stack[top]))	
			{
				char item =pop();
				pre[j++]=item;
			}
			push(x);
		}
		
		i--;
	}
	while(top!=0)
	{
		pre[j++]=pop();
	}
	
	printf("Prefix is: %s",strrev(pre));
	
	
}

