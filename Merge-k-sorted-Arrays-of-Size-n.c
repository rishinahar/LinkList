// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;
 
// A Linked List node
typedef struct Node
{
    int data;
    Node* next;
}Node;
 
/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Takes two lists sorted in increasing order, and merge
   their nodes together to make one big sorted list. Below
   function takes O(Log n) extra space for recursive calls,
   but it can be easily modified to work with same time and
   O(1) extra space  */
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

// optimized solution to merge two lists 
Node * MergeLists(Node *list1, Node *list2) {
  if (!list1) return list2;
  if (!list2) return list1;
 
  Node *head;
  if (list1->data < list2->data) {
    head = list1;
  } else {
    //  swapping b/w list1 and list2 
    head = list2;
    list2 = list1;
    list1 = head;
  }
  while(list1->next && list2) {
    if (list1->next->data > list2->data) {
      Node *tmp = list1->next;
      list1->next = list2;    
      list2 = tmp; // list2 is placeholder to keep the large elements found while traversing the list

    }
    list1 = list1->next;
  } 
  if (!list1->next) list1->next = list2;
  return head;
} 


// The main function that takes an array of lists
// arr[0..last] and generates the sorted output
Node* mergeKLists(Node* arr[], int last)
{
    // repeat until only one list is left
    while (last != 0)
    {
        int i = 0, j = last;
 
        // (i, j) forms a pair
        while (i < j)
        {
            // merge List i with List j and store
            // merged list in List i
            arr[i] = MergeLists(arr[i], arr[j]);
 
            // consider next pair
            i++, j--;
 
            // If all pairs are merged, update last
            if (i >= j)
                last = j;
        }
    }
 
    return arr[0];
}
 
// Utility function to create a new node.
Node *newNode(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list
 
    // an array of pointers storing the head nodes
    // of the linked lists
    Node* arr[k];
 
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
 
    // Merge all lists
    Node* head = mergeKLists(arr, k - 1);
 
    printList(head);
 
    return 0;
}