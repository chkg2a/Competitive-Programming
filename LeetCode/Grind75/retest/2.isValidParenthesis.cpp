#include <cstdio>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    unordered_map<char, char> umap = {
      {'}', '{'},
      {']', '['},
      {')', '('},
    };
    for(char c : s){
      if(umap.count(c)){
        if(!stk.empty() && umap[c] == stk.top())
          stk.pop();
        else
          stk.push(c);
      }else{
        stk.push(c);
      }
    }
    return stk.empty();
  }
};

int main() {
  // string s = "{[()]}";
  string s = "{()]}";
  Solution sol;
  printf("%b", sol.isValid(s));

  return 0;
}
