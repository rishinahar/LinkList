#include <iostream>
using namespace std;

struct nodeType
{
    int data;
    nodeType *next;
};

nodeType *first ;
nodeType *firstlist;
nodeType *firstmergelist;
nodeType *lastmergelist;
nodeType *last ;
nodeType *lastlist;
nodeType *newNode;
int num;

void insert(int a);
void insertlist(int a);
void insertmergelist(int num); 
void display();
void swap(int,int);
void swapdata (int, int);
void deleter();
void movefirsttolast();
void mergelist();

int main()
{   int count=0;
    for ( num= 1; num<6; num = num+1)
    {
        //cout<<" \n you entered no.";
        insert(num);
    } 
    insert(40);
    for ( num= 5; num <11; num = num+1)
    {
        //cout<<" \n you entered no.";
        insertlist(num);
    } 



    /*int  run[3] = { 3,  1, 2};
    
    for(int i=0;i<3; i++)
    {  //cout<<"For loop running for st ==>> "<<i;
      if(run[i]==first->data){
       //cout<< " if called " << i;
       count++;
       deleter();
      }
      
      else {

      //cout<< " else  called " << i;

      while(run[i]!=first->data){
       // cout<< "\n else while called " << run[i];
        //cout<< " \t " << first->data;

        movefirsttolast();
        
        //cout<< " after moving first \t " ;
        //display();
        count++;
      }

      if(run[i]==first->data){
       count++;
       deleter();
       //cout<< "\n if called after deleting " << i;
       //display();
      }
    }
      
 }*/
   //display();  
   cout<<" \n";
   //swapdata(3,2);
   //cout<<" \n";
   mergelist();
   display(); 
 return 0;
}
void mergelist()
{
  nodeType *temp1;
    //temp1 = NULL;

  nodeType *temp2;
    //temp2 = NULL;

  temp1 = first;
  temp2 = firstlist;
  
 
/* while(temp1 !=NULL && temp2 !=NULL)
{
   if ( temp1-> data > temp2->data)
    {   
      insertmergelist(temp1->data);
      temp1= temp1->next;
    }
    else if ( temp1-> data < temp2->data)
    {   
      insertmergelist(temp2->data);
      temp2= temp2->next;
    }
    
}*/ 

 
while( temp1 != NULL && temp2 != NULL)
{
   if ( temp1-> data < temp2->data)
    {   
      insertmergelist(temp1->data);
      temp1= temp1->next;
    }
    else if ( temp1-> data > temp2->data)
    {   
      insertmergelist(temp2->data);
      temp2= temp2->next;
    }
    else if ( temp1-> data == temp2->data)
    { 
      insertmergelist(temp1->data);
      temp1= temp1->next;  
      insertmergelist(temp2->data);
      temp2= temp2->next;
    }

    if (temp1 ==NULL)
    {
      while(temp2 !=NULL)
      {
      insertmergelist(temp2->data);
      temp2= temp2->next;
      }
    }
     else if (temp2 ==NULL)
    {
      while(temp1 !=NULL)
      {
      insertmergelist(temp1->data);
      temp1= temp1->next;
      }
    }
}
 

/* else 
  {
   firstmergelist = first;
   firstmergelist->next = firstlist;
   temp1= temp1->next;
   temp2= temp2->next; 
  } */
  
  //while(temp2 != NULL)
      
/*
  { cout << " before iff  "; 
    if (temp1-> data < temp2-> data)
  {
    cout << " iff  "; 
    //firstmergelist->next = temp1;
    //temp1= temp1->next;
  }
  else if (temp2-> data > temp1-> data)
  {
        cout << " else iff  "; 

    //firstmergelist->next = first;
    //temp2= temp2->next;
  }
  else 
  {
   //firstmergelist->next = first;
   //firstmergelist->next = firstlist;
   //temp1= temp1->next;
  }
      //temp2= temp2->next; 

  } */
  }

void display()
  {
   nodeType *current;
   current = firstmergelist;
   
   while (current != NULL)
  {
    cout << "\n we are printing "<<current->data << " ";
    current = current->next;
  }
  }

  void insert(int num) 
  {
        newNode = new nodeType;         // Create the new node
        newNode->data = num;            // and assign its data value
        newNode->next = NULL;           // make its next point to nothing
        if (first == NULL)              // If there is nothing in the list, then make the 
        {                            // newNode the first item and the last item
            first = newNode;
            last = newNode;
        }
        else                            // Else if first already has a value
        {                               // make the last item next to the newNode
            last->next = newNode;       // and make newNode the last item
            last = newNode;
        }
   }
   void insertlist(int num) 
  {
        newNode = new nodeType;         // Create the new node
        newNode->data = num;            // and assign its data value
        newNode->next = NULL;           // make its next point to nothing
        if (firstlist == NULL)              // If there is nothing in the list, then make the 
        {                            // newNode the first item and the last item
            firstlist = newNode;
            lastlist = newNode;
        }
        else                            // Else if first already has a value
        {                               // make the last item next to the newNode
            lastlist->next = newNode;       // and make newNode the last item
            lastlist = newNode;
        }
   }
    void insertmergelist(int num) 
  {
        newNode = new nodeType;         // Create the new node
        newNode->data = num;            // and assign its data value
        newNode->next = NULL;           // make its next point to nothing
        if (firstmergelist == NULL)              // If there is nothing in the list, then make the 
        {                            // newNode the first item and the last item
            firstmergelist = newNode;
            lastmergelist = newNode;
        }
        else                            // Else if first already has a value
        {                               // make the last item next to the newNode
            lastmergelist->next = newNode;       // and make newNode the last item
            lastmergelist = newNode;
        }
   }
   void swap (int x , int y)
   { 
    
    nodeType *temp;
    temp = NULL;

    nodeType *prevFirst;
    prevFirst = NULL;

    nodeType *currentFirst;
    currentFirst = first;
    
    nodeType *prevSecond;
    prevSecond = NULL;
   
    nodeType *currentSecond;
    currentSecond = first;


    cout << "swap called";

   while (currentFirst != NULL && currentFirst->data != x)
  {
     prevFirst = currentFirst;
     currentFirst = currentFirst->next;

  }

  while (currentSecond != NULL && currentSecond->data != y)
  {
     prevSecond = currentSecond;
     currentSecond = currentSecond->next;

  }

  if (currentFirst == NULL || currentSecond ==NULL)
      return;

   if (prevFirst != NULL)
   {
     prevFirst->next = currentSecond;
   }else{
    first = currentSecond;
   }
  
  if (prevSecond != NULL)
   {
     prevSecond->next = currentFirst;
   }else{
    first = currentFirst;
   }
    
    temp = currentFirst->next;
    currentFirst->next = currentSecond->next;
    currentSecond->next = temp;

  }

  void swapdata (int x, int y) 
  {
  nodeType * temp;
  nodeType * one;
  nodeType * two;

  nodeType *current;
   current = first;

 while (current != NULL)
 {
    if (current->data == x)
       one = current;

    if (current->data == y)
       two = current;

      current = current->next;

 }
    temp->data = one->data;
    one->data = two->data;
    two->data = temp->data;
  
  }

   void deleter()
   {

    first=first->next;
   }
   
   void movefirsttolast()
   {
   last->next = first;
   last=first;
   first=first->next;
   last->next=NULL;
   
   }
   
   
