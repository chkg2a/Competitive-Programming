#include <bitset>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    /*bool isPowerOfTwo(int n) {*/
    /*  if (n < 1){*/
    /*    return false;*/
    /*  }*/
    /*  int x = n;*/
    /*  int y = x - 1;*/
    /*  return x & y;*/
    /*}*/
    bool isPowerOfTwo(int n) {
      return n > 0 && ((1 << 30) % n) == 0;
    }
};

int main (int argc, char *argv[]) {
  Solution sol;
  cout << sol.isPowerOfTwo(16);

  return 0;
}
