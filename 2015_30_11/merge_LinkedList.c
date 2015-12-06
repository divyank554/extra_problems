#include <stdio.h>
#include <malloc.h>

struct node
{
int data;
struct node *next;
};

struct node *temp1 = NULL;
struct node *temp2 = NULL;
int count = 0;

struct node * insert(struct node *head)
{
	int len;
	printf("enter number of nodes\n");
	scanf("%d",&len);
	printf("enter the nodes\n");
	count++;
  	do
 	{
  		struct node *new_node,*current;

  		new_node=(struct node *)malloc(sizeof(struct node));
  
  		scanf("%d",&new_node->data);
  		new_node->next=NULL;

  		if(head==NULL)
  		{
 			head=new_node;
  			current=new_node;
  		}
  		else
  		{
  			current->next=new_node;
  			current=new_node;
  		}			

	len--;
 	
 	}while(len!=0);
 	
 	return head;
}

struct node* Smerge(struct node* temp1, struct node* temp2) 
{
  struct node* result = NULL;

  if (temp1 == NULL) 
     return(temp2);
  else if (temp2 == NULL) 
     return(temp1);
 
  if (temp1->data <= temp2->data) 
  {
     result = temp1;
     result->next = Smerge(temp1->next, temp2);
  }
  else
  {
     result = temp2;
     result->next = Smerge(temp1, temp2->next);
  }
  return(result);
}

void display(struct node * ptr)
{
struct node *new_node;
 printf("\nThe Linked List : ");
 new_node=ptr;
 while(new_node!=NULL)
   {
   printf("%d--->",new_node->data);
   new_node=new_node->next;
   }
  printf("NULL");
}


void main()
{
	temp1 = insert(temp1);
	temp2 = insert(temp2);
	display(temp1);
	display(temp2);
	struct node * result;
	result = Smerge(temp1,temp2);
	display(result);
}
