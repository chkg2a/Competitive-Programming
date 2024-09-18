#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int evalRPN(vector<string> &tokens) {
  stack<int> stk;
  double op1, op2, value;
  for (auto x : tokens) {
    if ((x[0] == '+' || x[0] == '-' || x[0] == '*' || x[0] == '/') &&
        x[1] == '\0') {
      op2 = stk.top();
      stk.pop();
      op1 = stk.top();
      stk.pop();
      switch (x[0]) {
      case '+':
        value = op1 + op2;
        break;
      case '-':
        value = op1 - op2;
        break;
      case '*':
        value = op1 * op2;
        break;
      case '/':
        value = op1 / op2;
        break;
      }
      stk.push(value);
    } else {
      int num;
      stringstream ss(x);
      while (ss >> num) {
        stk.push(num);
      }
    }
  }
  return stk.top();
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<string> s = {"10", "6", "9",  "3", "+", "-11", "*",
                      "/",  "*", "17", "+", "5", "+"};

  cout << evalRPN(s);
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
