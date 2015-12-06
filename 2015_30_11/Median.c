#include <stdio.h>
#include <malloc.h>

struct node
{
int data;
struct node *next;
};

struct node *start = NULL;

int printMiddle(struct node *head)
{
    struct node *temp1 = head;
    struct node *temp2 = head;
    int i=0,n;
    
	if (head!=NULL)
    {
        while (temp1 != NULL && temp1->next != NULL)
        {
        	i++;
            temp1 = temp1->next->next;
          	if(temp1 != NULL)
            	temp2 = temp2->next;
        }
        
    }
     n = temp2->data;
     printf("I = %d\n",i);
     if(i %2 != 0)
        return temp2->data;
    else 
    {
    	temp2 = temp2->next;
    	return (n+temp2->data)/2;
	}
        
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


void display()
{
struct node *new_node;
 printf("\nThe Linked List : ");
 new_node=start;
 while(new_node!=NULL)
   {
   printf("%d--->",new_node->data);
   new_node=new_node->next;
   }
  printf("NULL");
}


void main()
{
	insert();
	display();
 	int median =  printMiddle(start);
 	printf("median : %d\n",median);
}
