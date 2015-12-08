#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

void insert(struct node **start, int n1, int n2, int r)
{
	int temp1 = n1;
	int temp2 = n2;
 	while(r != 0)
 	{	
  		struct node *new_node,*current;

  		new_node=(struct node *)malloc(sizeof(struct node));
  		
  		printf("n1 : %d\n",n1);
  		printf("n2 : %d\n",n2);
  		if(n1 < n2)
  		{
		  	new_node->data = n1;
			n1 = n1 + temp1; 
  			new_node->next=NULL;
  		}
  		else if(n2 < n1)
  		{
  			new_node->data = n2;
			n2 = n2 + temp2; 
  			new_node->next=NULL;
		  }
		  else
		  {
		  	new_node->data = n1;
			n1 = n1 + temp1; 
			n2 = n2 + temp2;
  			new_node->next=NULL;
		  }

  		if(*start==NULL)
  		{
  			*start=new_node;
  			current=new_node;
  		}
  		else
  		{
  			current->next=new_node;
  			current=new_node;
 		 }

		r--;
 	
	 }
 
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
 
int main()
{
	struct node *head=NULL;
	int n1,n2,r;
	printf("enter number 1\n");
	scanf("%d",&n1);
	printf("enter number 2\n");
	scanf("%d",&n2);
	printf("enter the required index\n");
	scanf("%d",&r);
    insert(&head,n1,n2,r);
    display(head);
} 
