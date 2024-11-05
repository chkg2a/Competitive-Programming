#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    int freq[58] = {0};
    for (char c : s) {
      freq[c - 'A']++;
    }
    int len = 0;
    int hasOdd = 0;
    for (int f : freq) {
      // Checks even
      if ((f & 1) == 0){
        len += f;
      }
      else {
        len += (f - 1);
        hasOdd = 1;
      }
    }
    return len+hasOdd;
  }
};

int main() {
  string s = "abccccdd"; //7
  /*string s = "abaa"; //3*/
  Solution sol;
  cout << sol.longestPalindrome(s);

  return 0;
}
