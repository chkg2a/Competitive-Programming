/* 217. Contains Duplicate
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*bool containsDuplicate(vector<int>& nums) {*/
    /*  unordered_set<int> set;*/
    /*  for(auto x : nums){*/
    /*    if(set.count(x)){*/
    /*      return true;*/
    /*    }*/
    /*    set.insert(x);*/
    /*  }*/
    /*  return false;*/
    /*}*/
    bool containsDuplicate(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      for(int i =1; i < nums.size() + 1;i++){
        if(nums[i] == nums[i-1]){
          return true;
        }
      }
      return false;
    }
};

int main () {
  vector<int> nums = {1,2,3,1};
  Solution sol;
  cout << sol.containsDuplicate(nums);
    
  return 0;
}
