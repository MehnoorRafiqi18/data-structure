// Online C compiler to run C program online
#include <stdio.h>
#define Max 100
int top=-1;
int stack[Max];
void push();
int pop();
void peep();
void view();
int main() {
    int ch,item;
    
    while(1)
    {
        printf("1 for push, 2 for pop, 3 for peep and 4 to view: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter element to push: ");
            scanf("%d",&item);
            push(item);
        }
        else if(ch==2)
        {
            item=pop();
            if(item==-1)
                printf("Underflow\n");
            else
                printf("Popped item is %d\n",item);
        }
        else if(ch==3)
            peep();

        else if(ch==4)
            view();
        else
            break;
    }

    return 0;
}
void push(int item)
{
    if(top==Max-1)
        printf("stack overflow\n");
    else
        stack[++top]=item;
}
int pop()
{
    if(top==-1)
        printf("Underflow\n");
    else
        return stack[top--];
}
void peep()
{
    if(top==-1)
        printf("Stack empty\n");
    else
        printf("%d\n",stack[top]);
}
void view()
{
	int i;
    if(top==-1)
        printf("Stack empty\n");
    else
	{
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
