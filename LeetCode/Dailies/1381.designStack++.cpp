#include <bits/stdc++.h>
using namespace std;

class CustomStack {
private:
  vector<int> stackArray;

  vector<int> incrementArray;

  int topIndex;

public:
  CustomStack(int maxSize) {
    stackArray.resize(maxSize);
    incrementArray.resize(maxSize);
    topIndex = -1;
  }

  void push(int x) {
    if (topIndex < (int)(stackArray.size()) - 1) {
      stackArray[++topIndex] = x;
    }
  }

  int pop() {
    if (topIndex < 0) {
      return -1;
    }

    int result = stackArray[topIndex] + incrementArray[topIndex];

    if (topIndex > 0) {
      incrementArray[topIndex - 1] += incrementArray[topIndex];
    }

    incrementArray[topIndex] = 0;

    topIndex--;
    return result;
  }

  void increment(int k, int val) {
    if (topIndex >= 0) {

      int incrementIndex = min(topIndex, k - 1);
      incrementArray[incrementIndex] += val;
    }
  }
};

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  CustomStack stk = CustomStack(3);
  stk.push(1);
  stk.push(2);
  cout << stk.pop() << endl;
  stk.push(2);
  stk.push(3);
  stk.push(4);
  stk.increment(5, 100);
  stk.increment(2, 100);
  cout << stk.pop() << endl;
  cout << stk.pop() << endl;
  cout << stk.pop() << endl;
  cout << stk.pop() << endl;

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
