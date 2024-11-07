#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int count[32] = {0};
        int maximum = 0;
        for(auto x : candidates){
          int i = 0;
          while(x > 0){
            count[i++] += x & 1;
            x>>=1;
          }
        }
        for(auto x : count){
          maximum = max(maximum, x);
        }
        return maximum;
    }
};

int main () {
  vector<int> cadidates = {16,17,71,62,12,24,14};
  Solution sol;
  cout << sol.largestCombination(cadidates);

  return 0;
}
