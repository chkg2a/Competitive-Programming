#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  vector<vector<string>> output;
  unordered_map<string, vector<string>> stringStorage;

  for (auto x : strs) {
    string word = x;
    sort(word.begin(), word.end());
    stringStorage[word].push_back(x);
  }

  for (auto x : stringStorage) {
    output.push_back(x.second);
  }

  return output;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  cout << "Output : ";

  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  for (auto x : groupAnagrams(strs)) {
    for (auto y : x) {
      cout << y << endl;
    }
  }

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
