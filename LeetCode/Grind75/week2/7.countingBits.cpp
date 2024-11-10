/* 338. Counting bits
 * Given an integer n, return an array ans of length n + 1 such that for each i
(0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
      ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
  }
  /*vector<int> countBits(int n) {*/
  /*  vector<int> ans;*/
  /*  for (int i = 0; i <= n; i++) {*/
  /*    ans.push_back(countOneBit(i));*/
  /*  }*/
  /*  return ans;*/
  /*}*/
  /*int countOneBit(int n) {*/
  /*  int bits = 0;*/
  /*  while (n) {*/
  /*    bits += (n & 1);*/
  /*    n >>= 1;*/
  /*  }*/
  /*  return bits;*/
  /*}*/
};

int main() {
  /*int n = 2; // 0 1 1*/
  int n = 5; // 0 1 1 2 1 2
  Solution sol;
  for (auto x : sol.countBits(n)) {
    cout << x << ' ';
  }

  return 0;
}
