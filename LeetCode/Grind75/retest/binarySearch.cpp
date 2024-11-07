// 1:54
// 0:58
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int low = 0;
      int high = nums.size() -1;
      while (low < high){
        int mid = low + (high - low) /2;
        if(nums[mid] > target){
          high = mid;
        }else if(nums[mid] < target){
          low = mid+1;
        }else{
          return mid;
        }
      }
      return -1;
    }
};

int main () {
  vector<int> nums = {-1,0,3,5,9,12};
  int target = 9;
  Solution sol;
  cout << sol.search(nums, target);

  return 0;
}
