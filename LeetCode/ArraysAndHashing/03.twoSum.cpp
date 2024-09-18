#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// vector<int> twoSum(vector<int>& nums, int target) {
//   vector<int> output;
//   for(int i = 0; i < nums.size(); i++) {
//     for(int j = 0; j < nums.size(); j++){
//       if(nums[i] + nums[j] == target){
//         output.push_back(i);
//         output.push_back(j);
//         return output;
//       }
//     }
//   }
//   return output;
// }
vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> output;
  unordered_map<int,int> ns;
  for(int i =0 ; i < nums.size(); i++){
    if(ns.count(target - nums[i])){
      output.push_back(i);
      output.push_back(ns[target - nums[i]]);
      return output;
    }
    ns[nums[i]] = i;
  }
  return output;
}

int main (int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<int> nums;
  for(int i = -1000000; i < 1000000; i++){
    nums.push_back(i);
  }
  int target = 6992;
  for (auto x : twoSum(nums,target)){
    cout << x << endl;
  }

  std::cout <<  std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); 
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds " << std::endl;
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); 
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";


  return 0;
}
