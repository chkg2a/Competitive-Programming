/*
 * 20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true
 */

#include <bits/stdc++.h>
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

int main() {
  string s = "{[()]}";
  Solution sol;
  cout << sol.isValid(s);

  return 0;
}
