#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int in;
  cin >> in;
  int count = 0;
  string s;
  for (int i = 0; i <= in; i++) {
    getline(cin, s);
    if (s[0] == '1') {
      if (s[2] == '1' || s[4] == '1') {
        count++;
      }
    } else {
      if (s[2] == '1' && s[4] == '1') {
        count++;
      }
    }
  }
  cout << count;

  return 0;
}
