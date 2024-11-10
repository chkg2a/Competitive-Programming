/* 876.Middle of the Linked List
 * Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
*/
#include <bits/stdc++.h>
#include <chkg2a/fn_ll.h>
using namespace std;
using namespace chk;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      ListNode * slow = head;
      ListNode * fast = head;
      while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
    }
    /*ListNode* middleNode(ListNode* head) {*/
    /*  ListNode * arr[100];*/
    /*  int i = 0;*/
    /*  ListNode * current = head;*/
    /*  while(current){*/
    /*    arr[i++] = current;*/
    /*    current=current->next;*/
    /*  }*/
    /*  return arr[(i % 2 == 0 ? i/2 + 1 : (i/2))];*/
    /*}*/
};

int main () {
  List root = list_init();
  list_addRear(root, 5);
  list_addRear(root, 10);
  list_addRear(root, 15);
  list_addRear(root, 20);
  list_addRear(root, 25);
  list_display(root);
  Solution sol;
  cout << endl;
  List middle = sol.middleNode(root);
  list_display(middle);

  return 0;
}
