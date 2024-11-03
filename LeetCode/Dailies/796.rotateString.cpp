#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubledString = s + s;
        /*return doubledString.find(goal) < doubledString.length();*/
        return doubledString.contains(goal);
    }
};

int main () {
  string s = "abcde", goal = "cdeab";
  Solution sol;
  cout << sol.rotateString(s,goal);

  return 0;
}
