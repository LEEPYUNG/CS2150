/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date:1/27/2020
	File Name:List.cpp
*/

#include "List.h"
#include <iostream>
using namespace std;

// The default constructor.
// It should initialize all private data members
// and set up the basic list structure with the dummy head and tail nodes.
List::List(){
 count = 0;

 //Initializing a node pointer to a ListNode object.
 head = new ListNode();
 tail = new ListNode();
 
 head -> next = tail;
 head -> previous = NULL;
 tail -> previous = head;
 tail -> next = NULL;
}

// The copy constructor.
// It should create a **new** list of ListNodes whose contents
// are the same values as the ListNodes in `source`.
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// The destructor.
// It should empty the list and reclaim the memory allocated in the constructor for head and tail.
List::~List() {
  //makEmpty() deletes all nodes except the head and tail.
  makeEmpty();
  //Because the head and tails were not deleted, delete them manually.
  delete head;
  delete tail;
}

// The copy assignment operator.
// It should copy the contents of every ListNode in `source`
// into an **existing** list (the reference to the calling List object itself).
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}


// Returns true if empty, else false
//CHECK this

 bool List::isEmpty() const {
   if(count == 0)
     return true;
   else
     return false;
 }

// Removes (deletes) all items except the dummy head/tail.
// The list should be a working empty list after this.
 void List::makeEmpty(){
   //Creates an iterator that starts at the first tail.
   ListItr itr = first();

   while(!isEmpty()){
     itr.current -> next = NULL;
     itr.current -> previous = NULL;
     itr.moveForward();
     count--;
   }
   
   head -> next = tail;
   tail -> previous = head;
   
 }

// Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty li324st!)
ListItr List::first(){
 ListItr * itr = new ListItr(head -> next);
  return *itr;
 }

// Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
 ListItr List::last(){
   ListItr* itr = new ListItr(tail -> previous);
   return *itr;
 }

// Inserts x after current iterator position
 void List::insertAfter(int x, ListItr position){
   ListNode* n = new ListNode();
   n->value = x;

   n->next = position.current-> next;
   n->previous= position.current;
   position.current-> next = n;
   n->next -> previous = n;

   count++;
 }

// Inserts x before current iterator position
 void List::insertBefore(int x, ListItr position){
   ListNode* n = new ListNode();
   n->value = x;

   n -> next = position.current;
   n -> previous = position.current -> previous;

   position.current -> previous -> next = n;
   position.current -> previous = n;

   count++;
   
 }

// Inserts x at tail of list
 void List::insertAtTail(int x){
   ListNode *temp = new ListNode();
   temp->value = x;

   temp -> next = tail;
   temp-> previous = tail -> previous;
   tail -> previous -> next = temp;
   tail -> previous = temp;

   count++;
 }

 
// Returns an iterator that points to the first occurrence of x.
// When the parameter is not in the list, return a ListItr object that points to the dummy tail node.
// This makes sense because you can test the return from find() to see if isPastEnd() is true.
ListItr List::find(int x){
  ListItr *itr = new ListItr(first());
   
  while(!(itr -> isPastEnd())){
    if(itr -> current -> value == x){
      return *itr;
      break;
    }
    else
      itr -> moveForward();
   }
  itr -> current = tail;
  return *itr;
  
 }

// Removes the first occurrence of x
 void List::remove(int x){
   ListItr itr = find(x);

   if(itr.current -> value == x){
     itr.current -> next -> previous = itr.current -> previous;
     itr.current -> previous -> next = itr.current -> next;

     itr.current -> next = NULL;
     itr.current -> previous = NULL;
     count--;
     
     delete itr.current;
   }
   
 }

// Returns the number of elements in the list
 int List::size() const{
   return count;
 }





// prints list forwards (head -> tail) when forward is true
// or backwards (tail -> head) when forward is false
// You **must** use your ListItr class to implement this function!


void printList(List& source, bool forward){

   
   if(forward){
     //Creates a new iterator pointer using the source, this points to the first node after the head
     ListItr itr = source.first();  
     while(!(itr.isPastEnd())){
       cout << itr.retrieve() << endl;
       itr.moveForward();
     }
   }
   else{
       ListItr itr = source.last();   
       while(!(itr.isPastBeginning())){
	 cout <<  itr.retrieve()  << endl;
       itr.moveBackward();
   }
 }

  
 }
