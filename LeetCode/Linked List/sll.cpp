#include "sll.h"
#include <iostream>

using namespace std;

List getNode(int data) {
  List temp = new Node;
  temp->data = data;
  temp->next = NULL;
  return temp;
}
List init() { return getNode(0); }

void addRear(List head, int data) {
  List temp = getNode(data);
  List p = head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = temp;
}

void addFront(List head, int data) {
  List temp = getNode(data);
  temp->next = head;
  head = temp;
}

void display(List head) {
  List p = head->next;
  while (p->next != NULL) {
    cout << p->data << "->";
    p = p->next;
  }
  cout << "NULL" << endl;
}
