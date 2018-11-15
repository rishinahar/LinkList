#include <iostream>
using namespace std;

struct nodeType
{
    int data;
    nodeType *link;
};

nodeType *first ;
nodeType *last ;
nodeType *newNode;
int num;

void insert(int a);
void display();
void deleter();
void movefirsttolast();

int main()
{   int count=0;
    for ( num=4; num>0; num--)
    {
        //cout<<" \n you entered no.";
        insert(num);
    }    
    int  run[4] = { 3,  1, 2,4};
    
    for(int i=0;i<4; i++)
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
        display();
        count++;
      }

      if(run[i]==first->data){
       count++;
       deleter();
       //cout<< "\n if called after deleting " << i;
       display();
      }
    }
      
 }
 cout<< "\n The final count is "<<count;
 return 0;
}
  void insert(int num) 
  {
        newNode = new nodeType;         // Create the new node
        newNode->data = num;            // and assign its data value
        newNode->link = NULL;           // make its link point to nothing
        if (first == NULL)              // If there is nothing in the list, then make the 
        {                            // newNode the first item and the last item
            first = newNode;
            last = newNode;
        }
        else                            // Else if first already has a value
        {                               // make the last item link to the newNode
            last->link = newNode;       // and make newNode the last item
            last = newNode;
        }
   }
   
   void deleter()
   {

    first=first->link;
   }
   
   void movefirsttolast()
   {
   last->link = first;
   last=first;
   first=first->link;
   last->link=NULL;
   
   }
   
   void display()
  {
   nodeType *current;
   current = first;
   
   while (current != NULL)
  {
    // cout << "\n we are printing "<<current->data << " ";
    cout <<current->data << " ";
    current = current->link;
  }
  cout<<"\n";
  }