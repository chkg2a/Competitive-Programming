#include <bits/stdc++.h>
using namespace std;

void generateLexicalNumbers(int currentNumber, int limit, vector<int> &result) {
  // If the current number exceeds the limit, stop recursion
  if (currentNumber > limit)
    return;

  // Add the current number to the result
  result.push_back(currentNumber);

  // Try to append digits from 0 to 9 to the current number
  for (int nextDigit = 0; nextDigit <= 9; ++nextDigit) {
    int nextNumber = currentNumber * 10 + nextDigit;
    // If the next number is within the limit, continue recursion
    if (nextNumber <= limit) {
      generateLexicalNumbers(nextNumber, limit, result);
    } else {
      break; // No need to continue if nextNumber exceeds limit
    }
  }
}

vector<int> lexicalOrder(int n) {
  vector<int> lexicographicalNumbers;
  // Start generating numbers from 1 to 9
  for (int start = 1; start <= 9; ++start) {
    generateLexicalNumbers(start, n, lexicographicalNumbers);
  }
  return lexicographicalNumbers;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  int n = 13;
  for(auto x : lexicalOrder(n)){
    cout << x << " ";
  };

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
