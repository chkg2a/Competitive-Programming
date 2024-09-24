#include <bits/stdc++.h>
using namespace std;

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
  unordered_set<int> arr1Prefixes;

  for (int val : arr1) {
    while (!arr1Prefixes.count(val) && val > 0) {

      arr1Prefixes.insert(val);

      val /= 10;
    }
  }

  int longestPrefix = 0;

  for (int val : arr2) {
    while (!arr1Prefixes.count(val) && val > 0) {

      val /= 10;
    }
    if (val > 0) {

      longestPrefix = max(longestPrefix, static_cast<int>(log10(val) + 1));
    }
  }

  return longestPrefix;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<int> arr1 = {5655359, 5655359, 5655359, 5655359, 5655359, 5655359};
  vector<int> arr2 = {5655359};
  cout <<  longestCommonPrefix(arr1,arr2);

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
