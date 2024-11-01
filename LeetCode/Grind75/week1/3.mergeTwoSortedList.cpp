/*
 * 21. Merge two Sorted List
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.



Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
*/

#include <bits/stdc++.h>
#include <chkg2a/fn_ll.h>
using namespace chk;

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *dummy = new ListNode, *tail;
    tail = dummy;
    while (list1 && list2) {
      if (list1->val <= list2->val) {
        tail->next = list1;
        list1 = list1->next;
      } else {
        tail->next = list2;
        list2 = list2->next;
      }
      tail = tail->next;
    }
    if (list1) {
      tail->next = list1;
    } else if (list2) {
      tail->next = list2;
    }
    return dummy->next;
  }
};

int main() {
  List l1 = list_init();
  List l2 = list_init();
  list_addRear(l1, 1);
  list_addRear(l1, 2);
  list_addRear(l1, 4);
  list_addRear(l2, 1);
  list_addRear(l2, 3);
  list_addRear(l2, 4);

  Solution sol;
  List list3 = sol.mergeTwoLists(l1, l2);
  list_display(list3);
  return 0;
}
