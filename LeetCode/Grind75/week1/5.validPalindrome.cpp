#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      string newS = "";
      for(char c : s){
        if(isalnum(c)){
          newS += tolower(c);
        }
      }
      int l = 0,r = newS.size()-1;
      while(l <= r){
        if(newS[l++] != newS[r--]){
          return false; 
        }
      }
      return true;
    }
};

int main () {
  Solution sol;
  string s = "race a car";
  cout << sol.isPalindrome(s);

  return 0;
}
