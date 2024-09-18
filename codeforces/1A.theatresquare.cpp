#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  getline(cin, s);
  double n, m, a;
  stringstream ss(s);
  ss >> n >> m >> a;
  long long num = (ceil(n / a)) * (ceil(m / a));

  cout << num;

  return 0;
}
