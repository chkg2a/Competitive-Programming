// 4:30
// 2:08
// 2:30
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int candidate = 0;
      int count = 0;
      for(int i : nums){
        if(count == 0){
          candidate =i;
          count++;
        }
        if(candidate == i){
          count++;
        }else{
          count = 0;
        }
      }
      count = 0;
      for(int i : nums){
        if(candidate == i){
          count++;
        }
      }
      if(count >= nums.size()/2){
        return candidate;
      }
      return -1;
    }
};

int main () {
  vector<int> nums = { 2,2,1,1,1,2,2 }; // 2
  /*vector<int> nums = { 2,2,1,1 }; // -1*/
  Solution sol;
  cout << sol.majorityElement(nums);
  return 0;
}
