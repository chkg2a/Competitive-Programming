#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
  unordered_set<char> s;
  for (int i = 0; i < jewels.size(); i++) {
    s.insert(jewels[i]);
  }
  int count = 0;
  for (int i = 0; i < stones.size(); i++) {
    if (s.find(stones[i]) != s.end())
      count++;
  }
  return count;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  string jewels = "z";
  string stones = "ZZ";
  /*string jewels = "aA";*/
  /*string stones = "aAAbbbb";*/

  cout << numJewelsInStones(jewels, stones);

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
