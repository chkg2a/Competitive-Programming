#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

struct Stack{
  int data[MAXSIZE];
  int atTop;
  stack<int> stk;
};

void init(Stack * s){
  s->atTop = -1;
}

bool stack_empty(Stack * s){
  return s->atTop == -1;
}

void push(Stack * s, int data){
  if(s->atTop == MAXSIZE -1){
    exit(1);
  }
  if(s->stk.empty()){
    s->stk.push(data);
  }else{
    if(s->stk.top() > data){
      s->stk.push(data);
    }
    else{
      s->stk.push(s->stk.top());
    }
  }
  s->data[++(s->atTop)] = data;
}

void pop(Stack * s){
  if(stack_empty(s)){
    exit(139);
  }
  s->atTop--;
  s->stk.pop();
}

int stack_top(Stack * s) {
  if(stack_empty(s)){
    exit(139);
  }
  return s->data[s->atTop];
}

int getMin(Stack * s){
  if(stack_empty(s)){
    exit(139);
  }
  return s->stk.top();
}
 

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  Stack stk;
  init(&stk);
  push(&stk,2);
  push(&stk,5);
  push(&stk,0);
  push(&stk,9);
  push(&stk,99);
  push(&stk,412);
  cout << "First shit" << endl;
  cout << getMin(&stk) << endl;
  cout << stack_top(&stk) << endl;
  pop(&stk);
  cout << "Second shit" << endl;
  cout << getMin(&stk) << endl;
  cout << stack_top(&stk) << endl;


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
