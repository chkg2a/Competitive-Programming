#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool hasDuplicate(vector<int> & nums){
  sort(nums.begin(), nums.end());
  for(int i = 0; i < nums.size()-1; i++){
    if (nums[i] == nums[i+1]){
      return true;
    }
  }
  return false; 
}

int main (int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  cout << "Output : ";

  vector<int> nums = {1,2,4,3,4};
  cout << hasDuplicate(nums);

  std::cout <<  std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(end - start); 
  std::cout << "Execution time: " << duration_s.count() << " seconds " << std::endl;
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); 
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds " << std::endl;
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); 
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";


  return 0;
}
