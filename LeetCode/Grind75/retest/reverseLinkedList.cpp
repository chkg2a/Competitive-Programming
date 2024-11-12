// 5:01
// 1:34
// 1:25

#include <bits/stdc++.h>
#include <chkg2a/fn_ll.h>
using namespace std;
using namespace chk;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
  }
};

int main() {
  List root = list_init();
  list_addRear(root, 5);
  list_addRear(root, 10);
  list_addRear(root, 15);
  list_addRear(root, 20);
  list_display(root);
  Solution sol;
  List reversed = sol.reverseList(root);
  cout << endl;
  list_display(reversed);

  return 0;
}
