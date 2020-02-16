//Program to implement a linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
	char info;
	struct node *link;
}*start=NULL,*temp;

void create_node(int n)
{
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> link = NULL;
	new_node -> info = n;
	if(start == NULL)
		start = new_node;
	else
	{
		temp = start;
		while (temp -> link != NULL)
			temp = temp->link;
		temp->link = new_node;
	}
}

int list_len()
{
	int i=0;
	temp = start;
	while (temp != NULL)
	{
		i++;
		temp = temp->link;
	}
	return i;
}


void delete_node() //Alternate deletion
{
	struct node *temp = start,*del_node=NULL;
	while (temp != NULL)
	{
		if(temp->link == NULL)
			break;
		del_node = temp->link;
		temp->link = del_node->link;
		free(del_node);
		temp = temp->link;
	}	
}

void display()
{
	printf("\nList : ");
	printf("\n");
	temp = start;
	while (temp != NULL)
	{
		printf("%c ",temp->info);
		temp = temp->link;
	}
}

void main()
{
	int i=0,n=0;
	char ele;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter element %d : ",i+1);
		getchar();
		scanf("%c",&ele);
		create_node(ele);
	}
	printf("\n");
	temp = start;
	while (temp != NULL)
	{
		printf("%c ",temp->info);
		temp = temp->link;
	}
	
	
	delete_node();
	display();
	
	
}