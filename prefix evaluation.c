//evaluation of prefix
#include<stdio.h>
#include<math.h>
#include<string.h>

int stack[100];
int top=-1;

void push(int item);
int pop();
int isOperator(char item);
int evaluate(char opr,int a,int b);

int main()
{
	char expr[100];
	printf("enter prefix expression with proper spaces between operands and operators: ");
	gets(expr);
	int i,a,b,r,len;
	i=strlen(expr)-1;
	

	while(i>=0)
	{
		if(expr[i]==' ')
		{
			i--;
			continue;
		}
			
		else if(!isOperator(expr[i]))
		{
			int num=0;
			int multiplier=1;
			while(expr[i]>='0' && expr[i]<='9')
			{
				num=num + (expr[i]-'0')*multiplier;
				multiplier*=10;
				i--;
			}
			push(num);
		}
		else
			{
				a=pop();
				b=pop();
				r=evaluate(expr[i],a,b);
				printf("a=%d b=%d r=%d\n",a,b,r);
				push(r);
			}
			i--;

	}
	printf("Result= %d",pop());
}

void push(int item){
	stack[++top]=item;	
}

int pop()
{
	return stack[top--];
}

int isOperator(char item)
{
	if(item=='+' || item=='-' || item=='*' || item=='/' || item=='^' || item=='%')
		return 1;
	else
		return 0;
}

int evaluate(char opr,int a,int b)
{
	if(opr=='+')
		return a+b;
	else if(opr == '-')
		return a-b;
	else if(opr=='*')
		return a*b;
	else if(opr == '/')
		return a/b;
	else if(opr=='^')
		return (pow(a,b));
	else if(opr == '%')
		return a%b;
}

