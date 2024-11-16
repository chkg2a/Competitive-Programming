#include <bits/stdc++.h>
#include <chkg2a/fn_ll.h>
using namespace std;
using namespace chk;

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode * fast = head, * slow = head;
      while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
          return true;
        }
      }
      return false;
    }
};

int main () {
  Solution sol;

  return 0;
}
