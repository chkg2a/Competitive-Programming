#include <cstdio>
#include <unordered_map>
#include <vector>
#include <chkg2a/fn_utility.h>
using namespace std;

class Solution {
public:
  bool checkDistinct(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (int a : nums) {
      if (umap.count(a)){
        return false;
      }
      umap[a]++;
    }
    return true;
  }
  int minimumOperations(vector<int> &nums) {
    int nOp = 0;
    int result = checkDistinct(nums);
    while (nums.size() > 2 && result != true) {
      nOp++;
      chk::display_vec(nums);
      nums.erase(nums.begin(), nums.begin() + 3);
      result = checkDistinct(nums);
    }
    if (result != true){
      nOp++;
    }
    return nOp;
  }
};

int main() {
  // vector<int> nums = {1, 2, 3, 4, 2, 3, 3, 5, 7};
  vector<int> nums = {4,5,6,4,4};
  Solution sol;
  printf("%d",sol.minimumOperations(nums));
  return 0;
}
