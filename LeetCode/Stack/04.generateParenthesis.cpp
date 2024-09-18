#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void backTrack(int n, int open, int close, vector<char> &output,
               vector<string> &results) {
  if (open == n && close == n) {
    string outString(output.begin(), output.end());
    results.push_back(outString);
  }
  if (open < n) {
    output.push_back('(');
    backTrack(n, open + 1, close, output, results);
    output.pop_back();
  }
  if (close < open) {
    output.push_back(')');
    backTrack(n, open, close + 1, output, results);
    output.pop_back();
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> output;
  vector<char> result;
  backTrack(n, 0, 0, result, output);
  return output;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  for (auto x : generateParenthesis(3)) {
    cout << x << endl;
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
