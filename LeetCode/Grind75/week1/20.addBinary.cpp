/* 67. Add Binary
 * Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};

int main () {
  /*string a = "11", b = "1"; // 100*/
  string a = "1010", b = "1011"; // 10101
  Solution sol;
  cout << sol.addBinary(a, b);

  return 0;
}
