#include <bits/stdc++.h>
#include <chkg2a/fn_utility.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k = k % nums.size();
      vector<int> rotated(nums.size());
      for(int i = 0; i < nums.size(); i++){
        rotated[(i+k)%nums.size()] = nums[i];
      }
      for(int i = 0 ; i < rotated.size() ;i++){
        nums[i] = rotated[i];
      }
    }
};

int main () {
  vector<int> nums = {1,2,3,4,5,6,7};
  int k = 3;
  Solution sol;
  chk::display_vec(nums);
  sol.rotate(nums, k);
  chk::display_vec(nums);

  return 0;
}
