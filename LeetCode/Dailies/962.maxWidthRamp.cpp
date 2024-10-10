#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n);

        // Initialize the array with indices
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // Sort indices based on corresponding values in nums and ensure
        // stability
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        });

        int minIndex = n;  // Minimum index encountered so far
        int maxWidth = 0;

        // Calculate maximum width ramp
        for (int i = 0; i < n; i++) {
            maxWidth = max(maxWidth, indices[i] - minIndex);
            minIndex = min(minIndex, indices[i]);
        }

        return maxWidth;
    }
};

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  Solution sol;
  vector<int> nums = {9,8,1,0,1,9,4,0,4,1};
  cout << sol.maxWidthRamp(nums);

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
