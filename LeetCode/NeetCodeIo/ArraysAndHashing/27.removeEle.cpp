#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int index = 0; 
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] != val){
          nums[index] = nums[i];
          index++;
        }
      }
      return index;
    }
};  

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  Solution sol;
  vector<int> nums = {0,1,2,2,3,0,4,2};
  int val = 2;
  cout << sol.removeElement(nums, val);

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
