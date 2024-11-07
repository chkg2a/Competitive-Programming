#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  // Memoization
  int climbStairs(int n, unordered_map<int, int> &memo) {
    if (n == 1 || n == 0) {
      return 1;
    }
    if (memo.find(n) == memo.end()) {
      memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
    }
    return memo[n];
  }
  int climbStairs(int n) {
    unordered_map<int, int> memo;
    return climbStairs(n, memo);
  }
  // Fibonacci
  /*int climbStairs(int n) {*/
  /*  unsigned long first = 1, second = 1;*/
  /*  for (int i = 0; i < n; i++) {*/
  /*    unsigned long temp = first + second;*/
  /*    first = second;*/
  /*    second = temp;*/
  /*  }*/
  /*  return (int)first;*/
  /*}*/
};

int main() {
  /*int n = 2; // 2*/
  /*int n = 3; // 3*/
  int n = 5; // 8
  Solution sol;
  cout << sol.climbStairs(n);

  return 0;
}
