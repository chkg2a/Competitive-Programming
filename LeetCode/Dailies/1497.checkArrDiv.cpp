#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        for (auto i : arr) remainderCount[(i % k + k) % k]++;

        for (auto i : arr) {
            int rem = (i % k + k) % k;

            if (rem == 0) {
                if (remainderCount[rem] % 2 == 1) return false;
            }

            else if (remainderCount[rem] != remainderCount[k - rem])
                return false;
        }
        return true;
    }
};

int main(){
  Solution s;
  vector<int> arr = {1,2,3,4,5,10,6,7,8,9};
  int k = 5;
  cout << s.canArrange(arr, k) << endl;
  return 0;
}
