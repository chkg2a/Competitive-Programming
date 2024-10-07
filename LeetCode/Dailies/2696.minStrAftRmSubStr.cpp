#include <bits/stdc++.h>
#include <istream>
using namespace std;

  
class Solution {
public:
    int minLength(string s) {
        // Continue processing while "AB" or "CD" substrings exist
        while (s.find("AB") != -1 || s.find("CD") != -1) {
            if (s.find("AB") != -1) {
                // Remove all occurrences of "AB"
                s.erase(s.find("AB"), 2);
            } else if (s.find("CD") != -1) {
                // Remove all occurrences of "CD"
                s.erase(s.find("CD"), 2);
            }
        }

        return s.length();
    }
};

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  
  Solution sol;
  cout << sol.minLength("ADFCACDB");

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
