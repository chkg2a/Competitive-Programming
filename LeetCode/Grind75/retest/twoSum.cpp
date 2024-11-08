// 1:11
// 6:11
// 3:24
// 0:49
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> umap;
      for(int i =0 ; i < nums.size(); i++){
        if(umap.count(target - nums[i])){
          return {umap[target - nums[i]], i};
        }
        umap[nums[i]] = i;
      }
      return {};
    }
};

int main () {
  vector<int> nums = {2,7,11,15}; //0 2
  /*vector<int> nums = {3,2,4}; // 1 2*/
  int target = 13;
  /*int target = 6;*/
  Solution sol;
  for(auto x : sol.twoSum(nums, target)){
    cout << x << ' ';
  }

  return 0;
}
