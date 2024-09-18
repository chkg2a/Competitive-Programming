#ifndef MYLL
#define MYLL

typedef struct Node {
  Node *next;
  int data;
} *List;

List init();
List getNode(int);
void addRear(List, int);
void addFront(List, int);
void display(List);

#endif
