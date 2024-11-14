/*
 * Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0 || x != 0 && x % 10 == 0) {
         return false;
       }
      int reversed = 0;
      int firstNum = x;
      while(x > 0){
        reversed = reversed * 10 + x % 10;
        x /= 10;
      }
     return (reversed == firstNum);
    }
    /*bool isPalindrome(int x) {*/
    /*   if(x <= 0 || x % 10 == 0) {*/
    /*     return false;*/
    /*   }*/
    /*  int reversed = 0;*/
    /*  while(x > reversed){*/
    /*    reversed = reversed * 10 + x % 10;*/
    /*    x /= 10;*/
    /*  }*/
    /* return (x == reversed || x == reversed / 10);*/
    /*}*/
};

int main () {
  /*int x = 121; // 1*/
  int x = 1123521; // 0
  Solution sol;
  cout << sol.isPalindrome(x);

  return 0;
}
