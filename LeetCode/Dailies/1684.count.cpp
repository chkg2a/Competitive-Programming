#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int countConsistentStrings(string allowed, vector<string> &words) {
  unordered_map<char, int> umap;
  for (auto x : allowed) {
    umap[x]++;
  }
  int count = 0;
  for (auto x : words) {
    int notCount = 0;
    for (auto c : x) {
      if (!umap.count(c)) {
        notCount++;
        break;
      }
    }
    if (notCount == 0) {
      count++;
    }
  }
  return count;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};
  string allowed = "ab";
  cout << counConsistentStrings(allowed, words);

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
