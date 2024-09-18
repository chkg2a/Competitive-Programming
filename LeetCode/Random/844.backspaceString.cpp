#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t) {
  stack<char> stk;
  string s1, s2;
  for (char &c : t) {
    if (c != '#') {
      stk.push(c);
    } else {
      if (!stk.empty()) {
        stk.pop();
      }
    }
  }
  while (!stk.empty()) {
    s1.push_back(stk.top());
    stk.pop();
  }
  for (char &c : s) {
    if (c != '#') {
      stk.push(c);
    } else {
      if (!stk.empty()) {
        stk.pop();
      }
    }
  }
  while (!stk.empty()) {
    s2.push_back(stk.top());
    stk.pop();
  }
  if (s1 == s2) {
    return true;
  }
  return false;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  string s = "a##c";
  string t = "#a#c";
  cout << backspaceCompare(s, t);

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
