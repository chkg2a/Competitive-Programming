#include <iostream>
#define MAXSIZE 100
#include <stack>
using namespace std;

class MinStack {
  int atTop;
  int *data;
  stack<int> stk;

public:
  MinStack() {
    data = new int[MAXSIZE];
    atTop = -1;
  }

  void push(int val) {
    if (atTop == MAXSIZE - 1) {
      return;
    }
    data[++atTop] = val;
    if (atTop == 0) {
      stk.push(val);
      return;
    }
    if (stk.top() <= data[atTop]) {
      stk.push(stk.top());
    } else {
      stk.push(val);
    }
  }

  void pop() {
    if (atTop == -1) {
      return;
    }
    stk.pop();
    atTop--;
  }

  int top() { return data[atTop]; }

  int getMin() { return stk.top(); }
};

int main(int argc, char *argv[]) {
  MinStack *stk = new MinStack();
  stk->push(1);
  stk->push(2);
  stk->push(0);
  cout << stk->getMin() << endl;
  stk->pop();
  cout << stk->top() << endl;
  cout << stk->getMin() << endl;
  return 0;
}
