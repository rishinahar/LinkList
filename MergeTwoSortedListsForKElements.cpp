//
//  MergeTwoSortedListsForKElements.cpp
//  
//
//  Created by Rishi Nahar on 14/10/17.
//
//

#include "MergeTwoSortedListsForKElements.hpp"

// From stack overflow  http://stackoverflow.com/questions/10707352/interview-merging-two-sorted-singly-linked-list

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node * createNode(int val){
    Node * temp = (Node *)malloc(sizeof(Node));
    if(temp){
        temp->data = val;
        temp->next = NULL;
    }
    return temp;
}
/* This function inserts node at the head of linked list */
void push(Node **headRef, int data){
    Node * newNode  = createNode(data);
    newNode->next = *headRef;
    *headRef  = newNode;
}

void printList(Node * head){
    while(head){
        printf("%d->" , head->data );
        head = head->next;
    }
    
    printf("NULL");
    printf("\n");
}
Node * MergeLists(Node *list1, Node *list2,int n) {
    int i=0;
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
    while(list1->next && list2 && i<n) {
        if (list1->next->data > list2->data) {
            Node *tmp = list1->next;
            list1->next = list2;
            list2 = tmp; // list2 is placeholder to keep the large elements found while traversing the list
            
        }
        list1 = list1->next;
        i++;
        printf("%d " , i );
    }
    printf("\n");
    //if (!list1->next) list1->next = list2;
    list1->next = NULL;
    return head;
}

// Through  recurssion
Node *MergeListsRecurssion(Node *list1, Node *list2) {
    int i=0;
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

int main(){
    Node * L1 = NULL;
    Node * L2 = NULL;
    Node * result = NULL;
    int carry = 0 ;
    /* creating list 1 */
    push(&L1,7);
    push(&L1,6);
    push(&L1,4);
    push(&L1,3);
    printList(L1);
    printf("\n");
    
    /* creating list 2 */
    push(&L2,3);
    push(&L2,4);
    push(&L2,6);
    push(&L2,7);
    printList(L2);
    printf("\n");
    
    L1 = MergeLists(L1,L2,3);
    printList(L1);
    printf("\n");
    
    printList(L2);
    return 0;
}
