// 3:36
#include <bits/stdc++.h>
#include <chkg2a/fn_ll.h>
using namespace std;
using namespace chk;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    }
};


int main () {
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
