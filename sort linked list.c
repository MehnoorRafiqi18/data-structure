#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next; 
};

struct node *head=NULL, *tail=NULL;

void Create();
void View();
void Sort();
int main()
{
	int ch;
	while(1)
	{
		printf("\n1 for create\n2 for view \n3 for Sort: ");
		scanf("%d",&ch);
		if(ch==1)
			Create();
		else if(ch==2)
			View();
		else if(ch==3)
			Sort(); //sorts in ascending order
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

void Sort()
{
	struct node *trav1,*trav2; 
	int temp;
	trav2=head;
	while(trav2!=NULL)
	{
		trav1=head;
		while(trav1->next!=NULL)
		{
			if((trav1->data)>(trav1->next->data))
			{
				temp=trav1->data;
				trav1->data=trav1->next->data;
				trav1->next->data=temp;
				
			}
			trav1=trav1->next;
		}
		trav2=trav2->next;
		
	}
	

}
