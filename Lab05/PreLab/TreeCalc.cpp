 /* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 2/25/2020
	File Name: TreeCalc.cpp
*/
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  //No code needed.
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  cleanTree(expressionStack.top()); //Calls cleanTree on top of the stack.
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {

  //Recursively goes down and deletes the node at the the spot.
    cleanTree(tree -> right); 
    cleanTree(tree -> left);
    delete tree;
  
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  
  
  TreeNode* node = new TreeNode(val); //Create new node with the val.

  if (val == "+" || val == "-" || val == "*" || val == "/" ){
    TreeNode* right = expressionStack.top(); //Make new node with popped off value of stack.
    expressionStack.pop(); //Pop off that node.

    TreeNode* left = expressionStack.top(); //Repeat as above two lines of code.
    expressionStack.pop();

    node -> right = right; //Set node to be inserted's left and right to popped nodes.
    node -> left = left;
  }

  //insert back onto stack.
  expressionStack.push(node); 
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
 
  if(tree == NULL)
    return;

  cout << tree -> value + " "  ; //Print this node first.
  
  if(tree -> left != NULL)
    printPrefix(tree -> left);
  
  if(tree -> right != NULL)
    printPrefix(tree -> right);

  cout << "";
  
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
if(tree == NULL)
    return;


  if(tree -> left != NULL) 
    printInfix(tree -> left);
  
   cout << tree -> value + " "; //Print this node .
   
  if(tree -> right != NULL)
    printInfix(tree -> right);

  cout << "";
  
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form

  if(tree == NULL)
    return;

   if(tree -> left != NULL)
    printPostfix(tree -> left);
   
  if(tree -> right != NULL)
    printPostfix(tree -> right);
  
    cout <<  tree -> value + " " ; //Print this node .

    cout << "";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result

  if(tree -> value == "+"){ //If value is +, add left and right children of current node.
    return (calculate(tree -> left) + calculate(tree -> right));
  }
  else if(tree -> value == "-"){ //If value if -, add left and right children of current node.
    return (calculate(tree -> left) - calculate(tree -> right));
  }
  else if(tree -> value == "*"){ //as above.
    return (calculate(tree -> left) * calculate(tree -> right));
  }
  else if(tree -> value == "/") { //as above.
    return (calculate(tree -> left) / calculate(tree -> right));
  }
  else
    return stoi(tree -> value); //If value isn't an operator, it must be a number. Return the number.
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  int ans = calculate(expressionStack.top());  
    return ans;
}
