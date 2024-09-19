#include <bits/stdc++.h>
using namespace std;

vector<int> diffWaysToCompute(string expression) {
  vector<int> results;

  // Base case: if the string is empty, return an empty list
  if (expression.length() == 0)
    return results;

  // Base case: if the string is a single character, treat it as a number
  // and return it
  if (expression.length() == 1) {
    results.push_back(stoi(expression));
    return results;
  }

  // If the string has only two characters and the first character is a
  // digit, parse it as a number
  if (expression.length() == 2 && isdigit(expression[0])) {
    results.push_back(stoi(expression));
    return results;
  }

  // Recursive case: iterate through each character
  for (int i = 0; i < expression.length(); i++) {
    char currentChar = expression[i];

    // Skip if the current character is a digit
    if (isdigit(currentChar))
      continue;

    // Split the expression into left and right parts
    vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
    vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));

    // Combine results from left and right parts
    for (int leftValue : leftResults) {
      for (int rightValue : rightResults) {
        int computedResult = 0;

        // Perform the operation based on the current character
        switch (currentChar) {
        case '+':
          computedResult = leftValue + rightValue;
          break;
        case '-':
          computedResult = leftValue - rightValue;
          break;
        case '*':
          computedResult = leftValue * rightValue;
          break;
        }

        results.push_back(computedResult);
      }
    }
  }

  return results;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  string expr = "2-1-1";
  for (auto x : diffWaysToCompute(expr)) {
    cout << x << " ";
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
