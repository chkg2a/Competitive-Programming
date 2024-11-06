#include <iostream>
#include <stack>
using namespace std;

void addToStk(stack<int> & stk, stack<int> & minStk,const int & val){
  if(stk.empty()) {
    stk.push(val);
    minStk.push(val);
    return;
  }
  if(minStk.top() > val){
    minStk.push(val);
  }else{
    minStk.push(minStk.top());
  }
  stk.push(val);
}

int getMinEle(stack<int> minStk){
  return minStk.top();
}

int main () {
  stack<int> stk, minStk; 
  int addCount;
  int num;
  cout << "Please enter how many elements to add : ";
  cin >> addCount;

  while(addCount--){
    cout << "\nEnter : ";
    cin >> num;
    addToStk(stk, minStk, num);
    cout << "Min Ele so Far : " << getMinEle(minStk);
  }

  return 0;
}
