#include <bits/stdc++.h>
using namespace std;

void swap_without_var(int & a, int & b){
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}

int main () {
  int a = 99123;
  int b = 51235;
  cout << a << ',' << b << endl;
  swap_without_var(a,b);
  cout << a << ',' << b << endl;

  return 0;
}
