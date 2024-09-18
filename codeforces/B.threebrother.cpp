#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  getline(cin, s);
  int max = 6;
  int x, y;
  stringstream ss(s);
  ss >> x >> y;

  cout << 6 - x - y;

  return 0;
}
