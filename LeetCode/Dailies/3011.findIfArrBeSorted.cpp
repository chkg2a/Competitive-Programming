#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canSortArray(vector<int> &nums) {
    const uint8_t n = nums.size();
    uint16_t pmax = 0, cmin = 0, cmax = 0;
    uint8_t pcnt = 0;
    for (const uint16_t v : nums) {
      if (const uint8_t ccnt = __popcount(v); pcnt == ccnt) {
        cmin = min(cmin, v);
        cmax = max(cmax, v);
      } else if (cmin < pmax) {
        return false;
      } else {
        pmax = cmax;
        cmin = cmax = v;
        pcnt = ccnt;
      }
    }
    return cmin >= pmax;
  }
};

int main() { 
  vector<int> nums = {8,4,2,30,15};
  /*vector<int> nums = {3,16,8,4,2};*/
  Solution sol;
  cout << sol.canSortArray(nums);
  return 0; 
}
