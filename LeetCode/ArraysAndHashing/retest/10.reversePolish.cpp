#include <bits/stdc++.h>
using namespace std;

int operation(double op1, double op2, char c){
  switch(c){
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op1 / op2;
    default: exit(1);
  }
}

int evalRPN(vector<string> &tokens) {
   
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<string> tokens = {"1","2","+","3","*","4","-"};

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds " << std::endl;
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds " << std::endl;
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
