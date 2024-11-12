// 0:33
// 0:25

#include <bits/stdc++.h>
#include <chkg2a/fn_ll.h>
using namespace std;
using namespace chk;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    }
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
