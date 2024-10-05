#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long dividePlayers(vector<int> &skill) {
    sort(skill.begin(), skill.end());
    long long target = 0;
    for (auto x : skill) {
      target += x;
    }
    target /= skill.size() / 2;
    long long output = 0;
    for (int i = 0; i < skill.size()/2; i++) {
      if (target == skill[i] + skill[skill.size() - i - 1]) {
        output += skill[i] * skill[skill.size() - i - 1];
      } else {
        return -1;
      }
    }
    return output;
  }
};

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  Solution sol;

  vector<int> skills = {1, 2, 3, 3, 4, 5};
  cout << sol.dividePlayers(skills);

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
