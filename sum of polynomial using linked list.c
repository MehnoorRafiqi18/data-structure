#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int power;
	struct node *next; 
};

struct node *head1=NULL, *tail1=NULL;
struct node *head2=NULL, *tail2=NULL;
struct node *head3=NULL, *tail3=NULL;


void Create1();
void View1();
void Create2();
void View2();
void View3();
void sum();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1 to create 1st list\n2 to view 1st list\n3 to create 2nd list\n4 to view 2nd list\n5 to sum lists \n6 to view sum of polynomials: ");
		scanf("%d",&ch);
		if(ch==1)
			Create1();
		else if(ch==2)
			View1();
		else if(ch==3)
			Create2();
		else if(ch==4)
			View2();
		else if(ch==5)
			sum();
		else if(ch==6)
			View3();
		else
			break;	
	}
}

void Create1()
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
		printf("Enter power: ");
		scanf("%d",&(temp->power));
		temp->next=NULL;
		
		if(head1==NULL)
		{
			head1=temp;
			tail1=temp;
		}
		else
		{
			tail1->next=temp;
			tail1=temp;
		}
	}
	
}

void Create2()
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
		printf("Enter power: ");
		scanf("%d",&(temp->power));
		temp->next=NULL;
		
		if(head2==NULL)
		{
			head2=temp;
			tail2=temp;
		}
		else
		{
			tail2->next=temp;
			tail2=temp;
		}
	}
	
}

void View1()
{
	struct node *trav;
	trav=head1;

	while(trav!=NULL)
	{
		printf("%d, %d\t",trav->data,trav->power);
		trav=trav->next;
	}
}

void View2()
{
	struct node *trav;
	trav=head2;

	while(trav!=NULL)
	{
		printf("%d, %d\t",trav->data,trav->power);
		trav=trav->next;
	}
}

void View3()
{
	struct node *trav;
	trav=head3;

	while(trav!=NULL)
	{
		printf("%d, %d\t",trav->data,trav->power);
		trav=trav->next;
	}
}

void sum()
{
	struct node *temp, *trav1, *trav2;
	trav1= head1; trav2= head2;
	
	while(trav1 !=NULL && trav2!=NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		
		if(trav1->power>trav2->power)
		{
			temp->data=trav1->data;
			temp->power=trav1->power;
			trav1=trav1->next;
		}
		else if(trav2->power>trav1->power)
		{
			temp->data=trav2->data;
			temp->power=trav2->power;
			trav2=trav2->next;
		}
		else{
			temp->data=(trav1->data)+(trav2->data);
			temp->power=trav1->power;
			trav1=trav1->next;
			trav2=trav2->next;
		}
		
		if(head3==NULL)
		{
			head3=temp;
			tail3=temp;
		}
		else
		{
			tail3->next=temp;
			tail3=temp;
		}
	}
	
	while(trav1!=NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=trav1->data;
		temp->power=trav1->power;
		tail3->next=temp;
		tail3=temp;
		trav1=trav1->next;
	}
	
	while(trav2!=NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=trav2->data;
		temp->power=trav2->power;
		tail3->next=temp;
		tail3=temp;
		trav2=trav2->next;
	}
	// Terminate the merged list
	tail3->next = NULL;
}
