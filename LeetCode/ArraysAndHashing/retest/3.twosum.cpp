#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int,int> umap;
  for(int i = 0; i < nums.size(); i++){
    if(umap.count(target - nums[i])){
      return {umap[target -nums[i]],i};
    }
    umap[nums[i]] = i;
  }
  return {};
}
  

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<int> nums = {4,5,6};
  int target = 10;
  for (auto x : twoSum(nums,target)){
    cout << x << " ";
  }

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds " << std::endl;
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds " << std::endl;
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
