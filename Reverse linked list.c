#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next; 
};

struct node *head=NULL, *tail=NULL;

void Create();
void View();
void Reverse();
int main()
{
	int ch;
	while(1)
	{
		printf("\n1 for create\n2 for view \n3 for reverse: ");
		scanf("%d",&ch);
		if(ch==1)
			Create();
		else if(ch==2)
			View();
		else if(ch==3)
			Reverse();
		else
			break;	
	}
}

void Create()
{
	int n,i;
	struct node *temp;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&(temp->data));
		temp->next=NULL;
		
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}
	
}

void View()
{
	struct node *trav;
	trav=head;

	while(trav!=NULL)
	{
		printf("%d\t",trav->data);
		trav=trav->next;
	}
}

void Reverse()
{
	struct node *prev,*current,*trav;
	prev=NULL; current=head; trav=NULL;
	while(current!=NULL)
	{
		trav=current->next;
		current->next=prev;
		prev=current;
		current=trav;
	}
	head=tail;
	head=prev;

}

