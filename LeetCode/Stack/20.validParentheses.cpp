#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isValid(string s) {
  stack<char> c;
  unordered_map<char, char> closeOpen = {{'}', '{'}, {')', '('}, {']', '['}};

  for (auto x : s) {
    if (closeOpen.count(x)) {
      if (!c.empty() && c.top() == closeOpen[x]) {
        c.pop();
      } else {
        return false;
      }
    } else {
      c.push(x);
    }
  }
  if (c.empty()) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  cout << "Output : ";
  srand(time(0));

  string s = "[()]";
  cout << isValid(s);

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
