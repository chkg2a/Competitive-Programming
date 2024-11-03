/* 169. Majority Element
 * Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int candidate = 0;
      int count = 0;
      for(int i = 0; i < nums.size(); i++){
        if(i == 0 || count == 0){
          candidate = nums[i];
          count = 1;
        }
        else if(nums[i] != candidate){
          count--;
        }else{
          count++;
        }
      }
      count = 0;
      for(int i =0; i < nums.size(); i++){
        if(candidate == nums[i]){
          count++;
        }
      }
      if(count > nums.size()/2){
        return candidate;
      }
      return -1;
    }
};

int main () {
  vector<int> nums = { 2,2,1,1,1,2,2 };
  Solution sol;
  cout << sol.majorityElement(nums);
  return 0;
}
