//to insert node before or after node
//to delete all instances of element

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
	int control;
	printf("Press 1 for after node and 2 for before node: ");
	scanf("%d",&control);
	
	struct node *temp, *trav;
	int item;
	trav=head;
	
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter node to insert: ");
	scanf("%d",&(temp->data));
	temp->next=NULL;
	
	if(control==1)
	{
		printf("Enter the node after which you want to insert: ");
		scanf("%d",&item);
	
		while(trav->data!=item)
			trav=trav->next;
	
		if(trav==tail)// data item to stored after tail
		{
			trav->next=temp;
			tail=temp;
		}
		else{
			temp->next=trav->next;
			trav->next=temp;
		}	
	}
	else if(control==2)
	{
		printf("Enter the node before which you want to insert: ");
		scanf("%d",&item);
		if(item==head->data)
		{
			temp->next=head;
			head=temp;
		}
		 else{
		 	while(trav->next->data!=item)	
				trav=trav->next;
	
			temp->next=trav->next;
			trav->next=temp;
		 	
		 }
	}
}

void Del()
{
	struct node *trav, *temp;
	int item;
	printf("Enter the node to be deleted: ");
	scanf("%d",&item);
	trav=head;
	
	while(trav->next!=NULL)
	{
		
		if(trav->next->data==item)
		{
			temp=trav->next;
			trav->next=trav->next->next;
			free(temp);
			
			if(trav->next==tail)
			{
				tail=trav;
			}
		}
		else
			trav=trav->next;
	}
	if(head->data==item)// if head is to be deleted
		{
			temp=head;
			head=head->next;
			free(temp);
		}
}
