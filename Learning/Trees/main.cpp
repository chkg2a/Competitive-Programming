#include <iostream>
using namespace std;

typedef struct Node {
  int data;
  Node * left;
  Node * right;
} * Tree;

Tree getNode(int data){
  Tree node = new (struct Node); 
  node->right = NULL;
  node->left = NULL;
  node->data = data;
  return node;
}

Tree init(){
  return getNode(0);
}

bool isEmpty(Tree root){
  if(root->left == NULL && root->right == NULL){
    return true;
  }
  return false;
}
Tree goMaxRight(Tree root){
  Tree current = root; 
  while(current->right != NULL){
    current = current->right;
  }
  return current;
}

Tree goMaxLeft(Tree root){
  Tree current = root; 
  while(current->left != NULL){
    current = current->left;
  }
  return current;
}

void addLeft(Tree root, int data){
  Tree newNode = getNode(data);
  root->left = newNode;
}

void addRight(Tree root, int data){
  Tree newNode = getNode(data);
  root->right = newNode;
}

void display(Tree root){
  int maxLeftDepth = 0;
  int maxRightDepth = 0;
  Tree goLeft = root->left;
  Tree goRight = root->right;
}

void printNode(Tree root){
  cout << "   " << root->data << "  " << endl;
  cout << " /   \\" << endl;
  if(root->left != NULL && root->right != NULL){
    cout << root->left->data << "    " << root->right->data << endl;
  }else if(root->left != NULL){
    cout << root->left->data << "    " << root->right->data << endl;
  }else if(root->right != NULL){
    cout << root->left->data << "    " << root->right->data << endl;
  }
}

int findSum(Tree root){
  if(root == NULL){
    return 0;
  }
  return root->data + findSum(root->left) + findSum(root->right);
}

int main () {
  Tree head = init();
  addLeft(head,5);
  addRight(head,10);
  Tree left1 = goMaxLeft(head);
  Tree right1 = goMaxRight(head);
  addLeft(left1,20);
  addRight(left1,20);

  addLeft(right1, 10);
  addRight(right1, 5);
  cout << "head" << endl;
  printNode(head);
  cout << "left" << endl;
  printNode(left1);
  cout << "right" << endl;
  printNode(right1);

  cout << findSum(head);
  return 0;
}
