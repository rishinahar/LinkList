/* 
Rotate a Linked List
Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.
*/

#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
typedef struct node
{
    int data;
    struct node* next;
}Node;

// used function typedef to replace  struct node by Node
Node * rotateLinkList(Node *head , int k )
{
    Node * start = head;
    Node * last = NULL;
    Node * temp = NULL;
    int count =0;
    
    if (start == NULL )
        return;
    
    temp = start;
    while (temp->next != NULL)
    {
    	temp = temp-> next;
    }
   last = temp;

   while (count < k)
   {
      temp = start;
      last-> next = start;
      start = start->next;
      last = temp;
      last-> next = NULL;
      count++;
   }
   return start;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
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
 
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}    
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
  
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);           
 
     printf("\nGiven linked list \n");
     printList(head);
     head = rotateLinkList(head, 3);
 
     printf("\nReversed Linked list \n");
     printList(head);
 
     return(0);
}