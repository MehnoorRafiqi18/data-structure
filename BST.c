//Creating a BST and its traversal
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

void create_tree();
void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);


int main()
{
	create_tree();
	printf("preorder traversal: \n");
	preorder(root);
	
	printf("\ninorder traversal: \n");
    inorder(root);
    
	printf("\npostorder traversal:\n");
	postorder(root);
	
	
}

void create_tree()
{
	int n,i;
	struct node *temp, *trav;
	printf("Enter no of nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&temp->data);
		temp->left=NULL; temp->right=NULL;
		
		if(root==NULL)
			root=temp;
		else
		{
			trav=root;
			while(1)
			{
				if(temp->data<trav->data)
				{
					if(trav->left==NULL)
					{
						trav->left=temp;
						break;
					}
					else
						trav=trav->left;
				}
				else if(temp->data>trav->data)
				{
					if(trav->right==NULL)
					{
						trav->right=temp;
						break;
					}
					else
						trav=trav->right;
				}
				else if(trav->data==temp->data)
				{
					printf("invalid node");
					break;
				}
			}
		}		
	}
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	else{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root==NULL)
		return;
	else{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	else{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
