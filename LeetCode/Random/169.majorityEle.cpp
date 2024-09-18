#include <bits/stdc++.h>
#include <limits>
#include <unordered_map>
using namespace std;

/*int majorityElement(vector<int>& nums) {*/
/*  unordered_map<int, int> umap;*/
/*  for(auto x : nums) {*/
/*    umap[x]++;*/
/*  }*/
/*  int count = numeric_limits<int>::min();*/
/*  int max_val = numeric_limits<int>::min();*/
/*  for(auto x : umap){*/
/*    if(count < x.second){*/
/*      max_val = x.first;*/
/*      count = x.second;*/
/*    }*/
/*  }*/
/*  return max_val;*/
/*}  */
int majorityElement(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  return nums[n / 2];
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<int> nums = {3, 2, 3};
  cout << majorityElement(nums);

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s =
      std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds "
            << std::endl;
  auto duration_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds "
            << std::endl;
  auto duration_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
