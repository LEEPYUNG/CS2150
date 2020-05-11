/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 2/26/2020
	File Name: AVLTree.cpp
*/

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  
  insertHelper(x, root);
}

void AVLTree::insertHelper(const string& x, AVLNode*& curNode) {
  if(curNode == NULL) {
    curNode = new AVLNode();
    curNode -> value = x;
  }
  else if(x < curNode -> value)
    insertHelper(x, curNode -> left);
  else if(x > curNode -> value)
    insertHelper(x, curNode -> right);  
   
  balance(curNode);
   curNode -> height = max((height(curNode -> left)),height(curNode-> right)) + 1;
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
 return  pathToHelper(x, root);
}


string AVLTree::pathToHelper(const string& x, AVLNode* curNode)const{
  string pathWay = "";

  if(curNode -> value == "?")
    return "Current Node has no value.";
  else if( x < curNode -> value){
    pathWay += curNode -> value + " ";
    return pathWay +  pathToHelper(x, curNode -> left);
  }
  else if( x > curNode -> value){
    pathWay += curNode -> value + " ";
    return pathWay + pathToHelper(x, curNode -> right);
  }
  else {
    pathWay += curNode -> value;
    return curNode -> value;
  }
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
   string temp = findHelper(x, root) -> value;
  if(temp == x)
    return true;
  else
    return false;
}

//HELPER FUNCTION
AVLNode* AVLTree::findHelper(const string& x, AVLNode* curNode )const{
  if(curNode == NULL)
    return NULL;
  else if( x < curNode -> value)
    return findHelper(x, curNode -> left);
  else if( x > curNode -> value)
    return findHelper(x, curNode -> right);
  else
    return curNode; 
}

int AVLTree::Lsize(AVLNode* curNode){
  int count = 0;
  if(curNode -> left != NULL){
    Lsize(curNode -> left);
  }
  count++;
}

int AVLTree::Rsize(AVLNode* curNode){ 
  int count = 0;
  if(curNode -> right != NULL){
    Rsize(curNode -> right);
  }
  count++;
}


// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodesHelper(root);
}

int AVLTree::numNodesHelper(AVLNode* curNode)const{
  int size = 0;
  if(curNode == NULL)
    return 0;
  if(curNode -> left != NULL) //Call recursively on left subtree.
    size += numNodesHelper(curNode -> left);
  if(curNode -> right != NULL) //Call recursively on right subtree.
    size += numNodesHelper(curNode -> right);
  size += 1; //Add 1 for this current node.

  return size;
}



int AVLTree::getBalance(AVLNode* curNode){
  return (height(curNode -> right)-height(curNode -> left));
}


// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  if(n != NULL){

    
    if(getBalance(n) == 2){
      if(getBalance(n -> right) < 0){
	n -> right = rotateRight(n->right);
      }
     n = rotateLeft(n);     
    }
    if(getBalance(n) == -2){
      if(getBalance(n -> left) > 0){
      n -> left = rotateLeft(n -> left);
      }
      n = rotateRight(n);
    }
  }

  n -> height = max( (height( n -> left)), height( n-> right)) + 1;
  
}



// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* child = n -> right;
  AVLNode* temp  = child -> left;

  child -> left = n;
  n -> right = temp;

  n -> height = max( (height( n -> left)), height( n-> right)) + 1;
  child -> height = max((height(child -> left)),(height(child-> right))) + 1;
  
  return child;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  //Parameter is the grandparent. 
  //Child left subtree STAYS + Parent right subtree STAYS
  //Child RIGHT insert into parents subtree.


  AVLNode* child = n -> left;
  AVLNode* temp  = child -> right;

  child -> right = n;
  n -> left = temp;

  n -> height = max( (height( n -> left)), height( n-> right)) + 1;
  child -> height = max((height(child -> left)),(height(child-> right))) + 1;
  
  return child;
  
  
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
