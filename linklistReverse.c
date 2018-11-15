struct Node
{
	int data;
	struct Node* next;
};
struct Node * head;
void reverse (struct node * p )
{
	if (p->next == NULL)
	{
	    head = p;
		return;	
	}
 reverse(p->next);
 struct node *q = p-> next;
 q->next =p;
 p->next =NULL;
}

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