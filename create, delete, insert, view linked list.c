#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next; 
};

struct node *head=NULL, *tail=NULL;

void Create();
void View();
void Insert();
void Del();
int main()
{
	int ch;
	while(1)
	{
		printf("\n1 for create\n2 for delete \n3 for insert\n4 for view: ");
		scanf("%d",&ch);
		if(ch==1)
			Create();
		else if(ch==2)
			Del();
		else if(ch==3)
			Insert();
		else if(ch==4)
			View();
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

void Insert()
{
	struct node *temp, *trav;
	int item;
	trav=head;
	printf("Enter the node after which you want to insert: ");
	scanf("%d",&item);
	
	while(trav->data!=item)
		trav=trav->next;
		
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node to insert: ");
	scanf("%d",&(temp->data));
	temp->next=NULL;
	
	if(trav==tail)// data item to stored after tail
	{
		temp->next=trav->next;
		trav->next=temp;
		tail=temp;
	}
	else{
		temp->next=trav->next;
		trav->next=temp;
	}	
}

void Del()
{
	struct node *trav, *temp;
	int item;
	printf("Enter the node to be deleted: ");
	scanf("%d",&item);
	trav=head;
	if(head->data==item)// if head is to be deleted
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	else
	{
		while(trav->next->data!=item)	
			trav=trav->next;
			
		temp=trav->next;
		trav->next=trav->next->next;
		free(temp);
		
		if(trav->next==tail)// if tail is deleted
		{
			tail=trav;
		}
	}
}
