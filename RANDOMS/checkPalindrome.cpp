#include <iostream>
#include <stack>
#include <string>
using namespace std;

int checkPalindrome(int n){
  string number = to_string(n);
  string finalNumber;
  stack<char> stk;
  int i = 0;
  while(number[i] != '\0'){
    stk.push(number[i++]);
  }
  while(!stk.empty()){
    finalNumber += stk.top();
    stk.pop();
  }
  cout << finalNumber;
  return finalNumber == number;
}

int main () {
  int number = 12321;
  /*int number = 123;*/
  cout << checkPalindrome(number);

  return 0;
}
