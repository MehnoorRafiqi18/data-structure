#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *top=NULL, *temp;
void push(int item);
int  pop();
void view();
void reverse();
int main()
{
	int ch, item;
	while(1)
	{
		printf("\n1 to push, 2 to pop, 3 to view, 4 to reverse: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter item to push: ");
			scanf("%d",&item);
			push(item);
		}
			
		else if(ch==2)
		{
			item=pop();
			if(item==-1)
				printf("Underflow");
			else
				printf("popped item is %d",item);
		}
			
		else if(ch==3)
			view();
		else if(ch==4)
			reverse();
		else
			break;	
	}
}
void push(int item)
{
	temp=(struct node*)malloc(sizeof(struct node));
	
	if(temp==NULL)
		printf("Overflow");
	else
	{
		temp->data=item;
		temp->next=NULL;
	}
	
	if(top==NULL)
		top=temp;
	else
	{
		temp->next=top;
		top=temp;
	
	}
		
}
int  pop()
{
	int item;
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		item=top->data;
		temp=top;
		top=top->next;
		free(temp);
		return item;
	}
}
void view()
{
	if(top==NULL)
		printf("Stack empty");
	else
	{
		struct node *trav;
		trav=top;
		while(trav!=NULL)
		{
			printf("%d\n",trav->data);
			trav=trav->next;
		}
	}
}

void reverse()
{
	struct node *prev,*current,*trav;
	prev=NULL, trav=NULL, current=top;
	while(current!=NULL)
	{
		trav=current->next;
		current->next=prev;
		prev=current;
		current=trav;
	}
	top=prev;

}


