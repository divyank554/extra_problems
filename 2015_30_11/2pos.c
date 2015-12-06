#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int a[2];

struct node *start = NULL;
	
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


void display(struct node *ptr)
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
 
void ascending(struct node **head)
{
	int i=0;
	int count=0;
	struct node *prev = *head;
	struct node *curr = prev->next;
	while(curr->next != NULL && count!=2 )
	{
		if(curr->data > curr->next->data && count == 0 && curr->data > prev->data)
		{
			a[i] = curr->data;
			i++;
			count++;
		}
		
		if(curr->data < curr->next->data && prev->data != a[0] && count == 1 && curr->data < prev->data)
		{
			a[i] = curr->data;
			i++;
			count++;
		}
		
		if(curr->data < prev->data && count==0 )
		{
			a[i] = prev->data;
			i++;
			count++;
		}
		
			prev = prev->next;
			curr = curr->next;
	}
	
	if(curr->next == NULL && count==1)
	{
		a[i] = curr->data;
	}
	
}

void swapnode(struct node **head, int x, int y)
{
	
   if (x == y) return;

   struct node *prevX = NULL;
   struct node *currX = *head;
   while (currX && currX->data != x)
   {
       prevX = currX;
       currX = currX->next;
   }
 
   struct node *prevY = NULL, *currY = *head;
   
   while (currY && currY->data != y)
   {
       prevY = currY;
       currY = currY->next;
   }
 
   if (currX == NULL || currY == NULL)
       return;

   if (prevX != NULL)
       prevX->next = currY;
   else
       *head = currY;  
 
   if (prevY != NULL)
       prevY->next = currX;
   else 
       *head = currX;

   struct node *temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
   
   
   }

int main()
{
    insert();
    display(start);
    ascending(&start);
    swapnode(&start,a[0],a[1]);
     display(start);
} 
