//PKL4FR
//Pyung Lee
//PostLab 9
//linkedlist.c
//4/10/2020

#include <stdio.h>
#include <stdlib.h>


struct list_item{
  struct list_item* next;
  int datum;
};

struct linkedList {
  struct list_item* front;
};

int main(){
  //creating linkedList
  int num;
  struct linkedList *myList;
  myList = (struct linkedList*) malloc(sizeof(struct linkedList));

 
  //Asking input for how many nodes
  printf("Enter how many values to input: ");
  scanf("%d",&num);

  //Set the front pointer to NULL
  myList->front = NULL;

  //Creating nodes.
  for(int i = 1; i <= num; i++){
    int data = 0;                  //variable to hold data
    struct list_item *node;        //Holder node
    node = (struct list_item*) malloc(sizeof(struct list_item)); //allocate data
      
    printf("Enter Value %d: ", i); //get input for value
    scanf("%d", &data);

    node->datum = data;            //Put that data into node holder

    //storing data into node
    if(myList->front == NULL) {   //if the list doesn't have a first node, make this the first node.
      node->next = NULL;
      myList->front = node;
    }
    else {                        //First node already exists, make this new node the new front and 
      node->next = myList->front;
      myList->front = node;
    }

    
  }

  //printing out
  struct list_item *current = myList->front;    //Creating a pointer to a node to use as iterator
  
  for(int i = 0; i<num; i++){
    printf("%d\n", current->datum);
    current=current->next;                       //Make the pointer point to the next node in line
  }

  free(myList);                                  //free up the dynamic allocated variables
  //free(node);
  return 0;
}
