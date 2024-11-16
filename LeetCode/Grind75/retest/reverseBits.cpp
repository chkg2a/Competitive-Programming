// 6:05
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      uint32_t output = 0;
      uint32_t bit;
      for(int i = 0; i < 32; i++){
        bit = (n>>i) & 1;
        output = output | (bit << (31 - i));
      }
      return output;
    }
};

int main () {
  uint32_t n = 0b00000010100101000001111010011100; // 964176192
  Solution sol;
  cout << sol.reverseBits(n);

  return 0;
}
