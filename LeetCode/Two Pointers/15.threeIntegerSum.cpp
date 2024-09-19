#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> threeSum(vector<int> & nums) {
  vector<vector<int>> returnOutput;
  vector<int> output;
  unordered_map<int, int> n;
  for (auto x : nums) {
    n[x]++;
  }
  for (int i =0 ; i < nums.size(); i++) {
      for(int j=0; j < nums.size(); j++){
        if(nums[i] + nums[j] == n[-(nums[i]+nums[j])]){
          output.push_back(nums[i]);
          output.push_back(nums[j]);
        }
      }
  }
  returnOutput.push_back(output);
  return returnOutput;
}

int main() {
  vector<int> num = {1,0,-1};
  for (auto x : threeSum(num)){
    for (auto y : x){
      cout << y << endl;
    }
  }
}
