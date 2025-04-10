#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x, mask;
        --n;  // Reducing n by 1 to exclude x from the iteration

        // Step 1: Iterate over each bit position with mask starting at 1 and
        // shifting left
        for (mask = 1; n > 0; mask <<= 1) {
            // Step 2: If the corresponding bit in x is 0
            if ((mask & x) == 0) {
                // Set the bit in result based on the least significant bit of n
                result |= (n & 1) * mask;
                // Shift n to the right by 1 to process the next bit
                n >>= 1;
            }
        }

        return result;
    }
};

int main () {
  int n = 3, x = 4;
  Solution sol;
  cout << sol.minEnd(n,x);

  return 0;
}
