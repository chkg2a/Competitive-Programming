#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int minChangesRequired = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                minChangesRequired++;
            }
        }

        return minChangesRequired;
    }
};

int main () {
  string s = "1001"; //2
  /*string s = "10"    //1*/
  Solution sol;
  cout << sol.minChanges(s);

  return 0;
}
