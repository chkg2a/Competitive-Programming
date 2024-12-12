#include <algorithm>
#include<iostream>
using namespace std;

typedef struct Node {
  Node * left;
  int data;
  Node * right;
} * BST;

BST insert(BST root, int data){
  if(root == NULL){
    root = new Node;
    root->left = NULL;
    root->data = data;
    root->right = NULL;
  }else{
    if(root->data > data){
      root->left = insert(root->left,data);
    }else{
      root->right = insert(root->right,data);
    }
  }
  return root;
}

void preorderTraversal(BST root){
  if(root){
    cout << root->data << ' ';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

void inorderTraversal(BST root){
  if(root){
    inorderTraversal(root->left);
    cout << root->data << ' ';
    inorderTraversal(root->right);
  }
}

void postorderTraversal(BST root){
  if(root){
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << ' ';
  }
}

BST searchTree(BST root, int data){
  if(root){
    if(root->data > data)
      return searchTree(root->left, data);
    else if(root->data < data)
      return searchTree(root->right, data);
    else
      return root;
  }
  return NULL;
}

BST inorderSuccessor(BST root){
  BST temp = root->right;
  if(temp->right){
    while(temp->left){
      temp = temp->left;
    }
  }
  return temp;
}

BST searchParent(BST root, int data){
  if(root == NULL || root->data == data){
    return NULL;
  }
  if((root->left && root->left->data == data) ||
      (root->right && root->right->data == data)){
    return root; 
  }
  if(root->data > data)
    return searchParent(root->left,data);
  else
    return searchParent(root->right,data);
  return NULL;
}

void deleteNode(BST root,BST node){
  if(node == NULL) return;
  BST successor, parent;
  if(node->left == NULL && node->right == NULL){
    if(root == node){
      root = NULL;
    }
    parent = searchParent(root,node->data);
    if(parent->left == node){
      parent->left = NULL;
    }else{
      parent->right = NULL;
    }
    delete node;
  }
  else if(node->left == NULL || node->right != NULL){
    BST childNode = (node->left != NULL) ? node->left : node->right;
    if(root == node)
      root = childNode;
    parent = searchParent(root,node->data);
    if(parent->left == node)
      parent->left = childNode;
    else
      parent->right = childNode;
    delete node;
  }else{
    successor = inorderSuccessor(node);
    node->data = successor->data;
    deleteNode(root,successor);
  }
}

void destroyTree(BST root){
  if(root){
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
  }
}

int main(){
  BST root = NULL;
  root = insert(root,20);
  root = insert(root,10);
  root = insert(root,30);
  root = insert(root,45);
  root = insert(root,50);
  root = insert(root,40);
  inorderTraversal(root);
  cout << endl;
  BST toDelete = searchTree(root,40);
  deleteNode(root,toDelete);
  inorderTraversal(root);
  return 0;
}
