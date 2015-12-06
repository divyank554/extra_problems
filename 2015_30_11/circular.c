#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
 
void circularInsertion(struct node **head, int data)
{
	struct node *current = *head;
	struct node *nnode = (struct node*) malloc(sizeof(struct node));
	nnode->data = data;
	if( current == NULL)
	{
		nnode->next = nnode;
		*head = nnode;
	}
	else
  	{
    	while(current->next != *head)
        current = current->next;
        
    	current->next = nnode;
    	nnode->next = *head;
    	*head = nnode;
  	}
}
void print(struct node *start)
{
  struct node *temp;
 
  if(start != NULL)
  {
    temp = start;
    printf("\n");
    do {
      printf("%d->", temp->data);
      temp = temp->next;
    } while(temp != start);
     printf("%d", temp->data);
  }
}
 
 
int main()
{
    struct node* head = NULL;
    int len,i;
 	printf("enter the length : \n");
 	scanf("%d",&len);
 	printf("enter the numbers\n");
    for (i=0;i<len; i++)
    {
     	int num;
		 scanf("%d",&num);
       circularInsertion(&head, num);
   }
   print(head);
     printf("enter the number to insert\n");
    	int num;
		 scanf("%d",&num);
       circularInsertion(&head, num);   
    print(head);
       return 0;
}
