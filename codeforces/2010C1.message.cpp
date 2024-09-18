#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  string sorted;
  string s;
  cin >> s;
  int j = s.size() / 2;
  string newS = "";
  string check = "";
  for (int i = 0; i <= s.size() / 2; i++) {
    check += s[i];
    if (s[i] == s[j]) {
      newS += s[i];
    }
    j++;
  }
  if (s.size() % 2 == 0) {
    check.pop_back();
  }
  sort(s.front(), s.back());
  /*cout << check << endl;*/
  /*cout << newS << endl;*/
  /*cout << check.compare(newS) << endl;*/
  if (check[check.size() - 2] == newS[0]) {
    check += newS[0];
    check += newS[1];
  }
  if (check.compare(newS) == 0 && (s.size() % 2) == 0 &&
      check[check.size() - 2] != newS[0]) {
    cout << "NO";
  } else {
    cout << "YES" << endl;
    cout << check;
  }

  return 0;
}
