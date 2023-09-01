#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	float data;
	struct node *next; 
};

struct node *head=NULL, *tail=NULL;

void Create();
void View();
void ASV();
int main()
{
	Create();
	View();
	ASV();
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
		scanf("%f",&(temp->data));
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
		printf("%f\t",trav->data);
		trav=trav->next;
	} 
}

void ASV()
{
	struct node *trav;
	trav=head;
	float sum=0, avg, var=0, sd; int n=0;
	while(trav!=NULL)
	{
		sum=sum+(trav->data);
		trav=trav->next;
		n=n+1;
	}
	avg=sum/n;
	printf("\nAvg = %f",avg);
	trav=head;
	while(trav!=NULL)
	{
		var=var+pow(trav->data-avg,2);
		trav=trav->next;
		
	}
	var=var/n;
	printf("\nVariance = %f",var);
	
	sd=sqrt(var);
	printf("\nStandard Deviation = %f",sd);
}
