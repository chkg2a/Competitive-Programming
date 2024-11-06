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
};

/*int countBits(int number){*/
/*  return (number > 0) ? static_cast<int>(floor(log2(number) + 1)) : 1;*/
/*}*/

/*int countBits(int number) {*/
/*  int bits = 0;*/
/*  while(number > 0){*/
/*    number >>= 1;*/
/*    bits++;*/
/*  }*/
/*  return bits > 0 ? bits : 1;*/
/*}*/

int countBits(int number){
  std::bitset<32> bits(number);
  for(int i = 31; i >= 0; i--){
    if(bits[i] == 1){
      return i + 1;
    }
  }
  return 1;
}

int main() {
  int n = 8;
  /*Solution sol;*/
  /*for (int i : sol.countBits(n)) {*/
  /*  cout << i << ' ';*/
  /*}*/

  cout << countBits(n);
  return 0;
}
