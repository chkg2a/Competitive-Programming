// 1:31
// 3:41
// 1:27
// 1:20
// 1:40
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack<char> stk;
      unordered_map<char,char> umap = {
        {'}', '{'},
        {']', '['},
        {')', '('},
      };
      for(char c : s){
        if(umap.count(c)){
          if(!stk.empty() && umap[c] == stk.top()){
            stk.pop();
          }else{

          stk.push(c);
          }
        }else{
          stk.push(c);
        }
      }
      return stk.empty();
    }
};

int main () {
  /*string s = "({[]}))"; // 0*/
  string s = "({[]})"; // 1
  Solution sol;
  cout << sol.isValid(s);

  return 0;
}
