#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /*int hammingWeight(int n) {*/
  /*  int count = 0;*/
  /*  while (n) {*/
  /*    n &= (n - 1);*/
  /*    count++;*/
  /*  }*/
  /*  return count;*/
  /*}*/
  /*int hammingWeight(int n) {*/
  /*  int count = 0;*/
  /*  while(n){*/
  /*    count += n & 1;*/
  /*    n >>=1;*/
  /*  }*/
  /*  return count;*/
  /*}*/
  /*int hammingWeight(int n) {*/
  /*  return __builtin_popcount(n);*/
  /*}*/
  int hammingWeight(int n) {
    bitset<32> bits(n);
    return bits.count();
  }
};

int main() {
  int n = 11;
  Solution sol;
  cout << sol.hammingWeight(n);

  return 0;
}
