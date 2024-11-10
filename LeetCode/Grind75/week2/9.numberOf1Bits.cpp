/*
 * Given a positive integer n, write a function that returns the number of 
set bits
 in its binary representation (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
      int bits = 0;
      while(n){
        bits += (n & 1);
        n>>=1;
      }
      return (bits > 0) ? bits : 1;
    }
    /*int hammingWeight(int n) {*/
    /*  return __popcount(n);*/
    /*}*/
    /*int hammingWeight(int n) {*/
    /*  std::bitset<32> bits(n);*/
    /*  return bits.count();*/
    /*}*/
};

int main () {
  int n = 11; // 3
  /*int n = 5; // 2*/
  Solution sol;
  cout << sol.hammingWeight(n);

  return 0;
}
