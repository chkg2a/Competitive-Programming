#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    int n = nums.size();
    int totalSum = 0;

    for (int num : nums) {
      totalSum = (totalSum + num) % p;
    }

    int target = totalSum % p;
    if (target == 0)
      return 0;

    unordered_map<int, int> modMap;
    modMap[0] = -1;
    int currentSum = 0, minLen = n;

    for (int i = 0; i < n; ++i) {
      currentSum = (currentSum + nums[i]) % p;

      int needed = (currentSum - target + p) % p;

      if (modMap.find(needed) != modMap.end()) {
        minLen = min(minLen, i - modMap[needed]);
      }

      modMap[currentSum] = i;
    }

    return minLen == n ? -1 : minLen;
  }
};

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  Solution sol;
  vector<int> nums = {3, 1, 4, 2};

  int p = 6;
  cout << sol.minSubarray(nums, p);

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
