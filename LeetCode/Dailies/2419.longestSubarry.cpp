#include <iostream>
#include <algorithm>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int longestSubarray(vector<int> & nums){
  int max_val, ans, current_streak = 0;
  for (auto num : nums){
    if (max_val < num){
      max_val = num;
      ans = 0;
      current_streak = 0;
    }
    if(max_val == num){
      current_streak++;
    }else{
      current_streak = 0;
    }
    ans = max(ans,current_streak);
  }
  return ans;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<int> nums = {1,2,3,4};
  cout << longestSubarray(nums);

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
