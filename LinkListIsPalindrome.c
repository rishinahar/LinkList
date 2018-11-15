//Given a linked list, write a program to check if it is a palindrome


#include<stdio.h>
#include<stdlib.h>

/* Link list node */
typedef struct node
{
    int data;
    struct node* next;
}Node;
Node * headoFGivenList;
// used function typedef to replace  struct node -> Node
void  isPalindrome(Node *head )
{   Node *  start = head;
    Node * fast = head->next;
    Node * slow = head;
    Node * midList = NULL;
    Node * temp =NULL;

    int count =0;

    if (head == NULL )
        return ;

	  while(fast){
	  fast = fast->next;
	  if(fast){
	    fast = fast->next;
	    slow = slow->next;
	  }
	  }
	  midList = slow->next;
	  slow->next = NULL;

     printf("%d  ",midList->data );
     reverse(&midList);

     //midList = headoFGivenList;
     temp = midList;
     printf("%d  ",midList->data );

     /* condition for odd array length*/
     while (start->next!= NULL)
     {
     	if (start->data == temp ->data)
     	{
     		start = start->next;
     		temp = temp->next;

     	}
     	else
     		{   count =1;
     			break;
     		}
     }
     reverse(&midList);
      //midList = headoFGivenList;
      slow->next = midList;
      printf("%d  ", midList->data );
   if (count ==0)
   printf("List is palindrome ");
   else
   	printf("List is not palindrome ");

}
/* The method requires a  global head pointer to the list accessed by all methods
void reverse (struct node * p )
{
	if (p->next == NULL)
	{
	    headoFGivenList = p;
		return;
	}
 reverse(p->next);
 struct node *q = p-> next;
 q->next =p;
 p->next =NULL;
}*/

/* Function to reverse the linked list  Note that this
    function may change the head */
 void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
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
     push(&head, 1);
     push(&head, 2);
     push(&head, 3);
     push(&head, 4);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);

     printf("\nGiven linked list \n");
     printList(head);
     isPalindrome(head);
     printf("\nReversed Linked list \n");
     printList(head);

     return(0);
}
