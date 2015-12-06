#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node * start = NULL;
struct node *result;

void reverse(struct node** head)
{
    struct node* temp1;
    struct node* temp2;
      
    if (*head == NULL)
       return;   
 
    temp1 = *head;  
    temp2  = temp1->next;
 
    if (temp2 == NULL)
       return;   
 
    reverse(&temp2);
    temp1->next->next  = temp1;  
     
    temp1->next  = NULL;          
 
    *head = temp2; 
	             
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

void sortAsc(struct node **head)
{
	struct node *temp1 = *head;
	struct node *temp = temp1;
	struct node * temp2 = temp1->next;
	while(temp2->next != NULL)
	{
		if(temp2->data > temp2->next->data)
		{
			reverse(&temp2);
			break;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	
	temp1->next = NULL;
	result = Smerge(temp,temp2);
}

void insert()
{
	int len;
	printf("enter number of nodes\n");
	scanf("%d",&len);
	printf("enter the nodes\n");
 do
 {
  struct node *new_node,*current;

  new_node=(struct node *)malloc(sizeof(struct node));
  
  scanf("%d",&new_node->data);
  new_node->next=NULL;

  if(start==NULL)
  {
  start=new_node;
  current=new_node;
  }
  else
  {
  current->next=new_node;
  current=new_node;
  }

	len--;
 	
 }while(len!=0);
 
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


 int main()
{
	insert();
	display(start);
	sortAsc(&start);
	display(result);
}
