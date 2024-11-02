/* 242.Valid Anagram
 * Given two strings s and t, return true if t is an 
anagram
 of s, and false otherwise.
Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // 0ms
    bool isAnagram(string s, string t) {
      char count[26] = {0};
      for(char x : s){
        count[x - 'a']++;
      }
      for(char x : t){
        count[x - 'a']--;
      }
      for(int val : count){
        if(val != 0){
          return false;
        }
      }
      return true;
    }
  // 3ms
    /*bool isAnagram(string s, string t) {*/
    /*  sort(s.begin(),s.end());*/
    /*  sort(t.begin(),t.end());*/
    /*  return s == t;*/
    /*}*/
};

int main () {
  string s = "anagram";
  string t = "nagaram";
  /*string s = "rat", t = "car";*/
  Solution sol;
  cout << sol.isAnagram(s, t);

  return 0;
}
