#include <cmath>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =1;i<=n;i++){
            ans = ans ^ i;
        }
        for(int i =0;i<nums.size();i++){
            ans= ans^nums[i];
        }
        return ans;
    }
    /*int missingNumber(vector<int>& nums) {*/
    /*  int s = nums.size();*/
    /*  int maxN = s * (s+1) / 2;*/
    /*  int highestVal = 0;*/
    /*  for(auto x : nums) {*/
    /*    highestVal += x;*/
    /*  }*/
    /*  return maxN - highestVal;*/
    /*}*/
};

int main (int argc, char *argv[]) {
  Solution sol; 
  vector<int> nums = {0,1};
  cout <<  sol.missingNumber(nums);

  return 0;
}
