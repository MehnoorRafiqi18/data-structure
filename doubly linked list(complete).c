//doubly linked list
//insert before or after node
// delete one element or all instances of an element
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
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
		temp->prev=NULL;
		
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			temp->prev=tail;
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
	
	if(control==1)
	{
		printf("Enter the node after which you want to insert: ");
		scanf("%d",&item);
	
		while(trav->data!=item)
			trav=trav->next;
		
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter node to insert: ");
		scanf("%d",&(temp->data));
		temp->next=NULL;
		temp->prev=NULL;
	
		if(trav==tail)// data item to stored after tail
		{
			temp->next=trav->next;
			temp->prev=trav;
			trav->next=temp;
			tail=temp;
		}
		else{
			temp->next=trav->next;
			temp->prev=trav;
			trav->next=temp;
		}	
	}
	else if(control==2)
	{
		printf("Enter the node before which you want to insert: ");
		scanf("%d",&item);
		
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter node to insert: ");
		scanf("%d",&(temp->data));
		temp->next=NULL;
		temp->prev=NULL;
		
		if(item==head->data)
		{

			temp->next=head;
			head->prev=temp;

			head=temp;
		}
		 else{
		 	while(trav->data!=item)	
				trav=trav->next;
			
		
			temp->prev=trav->prev;
			trav->prev->next=temp;
			trav->prev=temp;
			temp->next=trav;
		 	
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
	
	int control;
	printf("Press 1 to delete first instance and 2 for all instances: ");
	scanf("%d",&control);
	
	if(control==1)
	{
		if(head->data==item)// if head is to be deleted
		{
			temp=head;
			head=head->next;
			head->prev=NULL;
			free(temp);
		}
		
		else
		{
			while(trav->data!=item)	
				trav=trav->next;
			
			if(trav==tail)
			{
				tail=tail->prev;
				tail->next=NULL;
				free(trav);
			}
			else
			{
				temp=trav;
				trav->prev->next=trav->next;
				trav->next->prev=trav->prev;
				free(temp);
			}
			
		
		
		}
	}
	else if(control==2)
	{
		while(trav!=NULL)
		{
			if(trav->data==item)
			{
				
				if(trav==head)// if head is to be deleted
				{
					temp=head;
					head=head->next;
					head->prev=NULL;
					free(temp);
					trav=head;
				}
				else if(trav==tail)
				{
					tail=tail->prev;
					tail->next=NULL;
					free(trav);
					trav=NULL;
				}
				else
				{
					temp=trav;
					trav->prev->next=trav->next;
					trav->next->prev=trav->prev;
					trav=trav->next;
					free(temp);
				}
			
			}
			else
				trav=trav->next;
			
		}
	
		
	}
	
}
