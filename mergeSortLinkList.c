/*
MergeSort(headRef)
1) If head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b); /* a and b are two halves */
/*3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
}Node;

void split(Node *head, Node **front, Node **back){
  
  Node *fast = head->next;
  Node *slow = head;
  
  while(fast){
  fast = fast->next;
  if(fast){
    fast = fast->next;
    slow = slow->next;
  }
  }
  *front = head; 
  *back = slow->next;
  slow->next = NULL;
}

// Through  recurssion
Node *MergeListsRecurssion(Node *list1, Node *list2) {
  if (list1 == NULL) return list2;
  if (list2 == NULL) return list1;

  if (list1->data < list2->data) {
    list1->next = MergeListsRecurssion(list1->next, list2);
    return list1;
  } else {
    list2->next = MergeListsRecurssion(list1 , list2->next);
    return list2;
  }
}

void mergeSort(Node **headRef){
  Node * front, *back;
  Node * head  = *headRef;
  if(head == NULL || head->next == NULL)
  return;
  printf("\n Original list:");
  printList(head);  
  split(head, &front, &back);

  printf("\n Splitted parts :\n");
  printList(front);
  printf("\n");
  printList(back);
  mergeSort(&front);
  mergeSort(&back);
  *headRef = MergeListsRecurssion(front, back);
  printf("\n After Merging:\n");
  printList(*headRef);
}

void push(Node **headRef, int data){
  Node * new_node  = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = *headRef;
  *headRef  = new_node;
}

void printList(Node * head){
  Node * current = head;
  while(current){
  printf("%d -> ", current->data);
  current = current->next;
  }
  printf("NULL");
}
int main(void) {
  // your code goes here
  Node *head = NULL;
  Node *front, *back;
  push(&head,5);
  push(&head,8);
  push(&head,7);
  push(&head,3);
  push(&head,1);
  mergeSort(&head);
  printf("\n");
  printList(head);
  return 0;
}
