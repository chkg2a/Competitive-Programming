#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int in;
  cin >> in;
  int count = 0;
  for (int i = 0; i < in; i++) {
    string s;
    cin >> s;
    if (s[1] == '+') {
      count++;
    } else if (s[1] == '-') {
      count--;
    }
  }
  cout << count;

  return 0;
}
