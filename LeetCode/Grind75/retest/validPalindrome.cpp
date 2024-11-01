// 1:30
#include <bits/stdc++.h>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      string n= "";
      for(char c : s){
        if(isalnum(c)){
          n += tolower(c);
        }
      }
      int l = 0, r = n.size()-1;
      while(l <= r){
        if(n[l++] != n[r--]){
          return false;
        }
      }
      return true;
    }
};

int main () {
  Solution sol;
  string s = "A man, a plan, a canal: Panama";
  /*string s = "race a car";*/
  cout << sol.isPalindrome(s);
  return 0;
}
