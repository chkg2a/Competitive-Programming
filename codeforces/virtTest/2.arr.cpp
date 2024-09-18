#include <cmath>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
  int in;
  cin >> in;
  string s;
  cin.ignore();
  getline(cin, s);
  float sum = 0;
  int temp;
  stringstream ss(s);
  int i = 0;
  while (ss >> temp) {
    sum += temp;
    i++;
  }
  if ((int)sum % 2 == 0 && (int)ceil(sum / 2) % 2 == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
