// 1:11
// 6:11
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    }
};

int main () {
  vector<int> nums = {2,7,11,15};
  /*vector<int> nums = {3,2,4};*/
  int target = 13;
  /*int target = 6;*/
  Solution sol;
  for(auto x : sol.twoSum(nums, target)){
    cout << x << ' ';
  }

  return 0;
}