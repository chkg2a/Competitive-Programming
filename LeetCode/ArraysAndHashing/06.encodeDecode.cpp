#include <algorithm>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string encode(vector<string> &strs) {
  string str = "";
  for (auto x : strs) {
    str.append(x);
    str.append("`");
  }
  return str;
}

vector<string> decode(string s) {
  vector<string> output;
  string a = "";
  for (auto x : s) {
    if (x == '`') {
      output.push_back(a);
      a = "";
      continue;
    }
    a += x;
  }
  return output;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  cout << "Output : ";
  srand(time(0));
  int x = rand() % 100000;

  vector<string> strs = {"neet", "code", "love", "you"};
  string encoded = encode(strs);
  for (auto x : decode(encoded)) {
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
