#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int findTheLongestSubstring(string s) {
  int prefixXOR = 0;

  int characterMap[26] = {0};
  characterMap['a' - 'a'] = 1;
  characterMap['e' - 'a'] = 2;
  characterMap['i' - 'a'] = 4;
  characterMap['o' - 'a'] = 8;
  characterMap['u' - 'a'] = 16;

  vector<int> mp(32, -1);
  int longestSubstring = 0;

  for (int i = 0; i < s.length(); i++) {

    prefixXOR ^= characterMap[s[i] - 'a'];
    if (mp[prefixXOR] == -1 and prefixXOR != 0)
      mp[prefixXOR] = i;

    longestSubstring = max(longestSubstring, i - mp[prefixXOR]);
  }

  return longestSubstring;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  string t = "leetcodeisgreat";

  cout << findTheLongestSubstring(t);

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
