#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

int sumFunc(string s) {
  int F, R;
  int encounter = 0;
  for (auto x : s) {
    if (isdigit(x)) {
      R = (int)x - '0';
      if (encounter == 0) {
        F = (int)x - '0';
      }
      encounter++;
    }
  }
  return (F * 10) + R;
}

int main() {
  ifstream iFile("input.txt");
  if (!iFile) {
    cerr << "Unable to launch input.txt" << endl;
    return 1;
  }
  string line;
  int sum = 0;

  while (getline(iFile, line)) {
    sum += sumFunc(line);
  }
  iFile.close();
  cout << sum;

  return 0;
}
