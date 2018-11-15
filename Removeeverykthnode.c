#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
          (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

struct node* removeknode(struct node** head_ref ,int n)
{
  struct node *prev = NULL;
  struct node *curr = *head_ref;
  
  int k = n-1;
  if (n==1)
    return *head_ref = NULL;

  while (curr)
  { 
    
    if (k==0)
    {
        prev->next = curr-> next;
        k=n-1;
    }
    prev = curr; 
    curr = curr-> next;
    k--;

  }
  return *head_ref;
}

void printList(struct node * head){
  struct node * current = head;
  while(current){
  printf("%d -> ", current->data);
  current = current->next;
  }
  printf("NULL");
}

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    printList(head);
    removeknode(&head , 4);
    printf("\n");
    printList(head);
    return 0;
}