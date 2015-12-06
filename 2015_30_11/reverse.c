#include<stdio.h>
#include<stdlib.h>
int i=0;
struct node
{
    int data;
    struct node* next;
};

struct node* start = NULL;

void reverseList(struct node** head)
{
    struct node* temp1;
    struct node* temp2;
      
    if (*head == NULL)
       return;   
 
    temp1 = *head;  
    temp2  = temp1->next;
    
    if (temp2 == NULL)
       return;
	      
    reverseList(&temp2);
    temp1->next->next = temp1;  
     
     temp1->next  = NULL;          
    *head = temp2;              
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


int main()
{
    insert();
    display();
	 reverseList(&start); 
    display();
     
    return 0;
}
