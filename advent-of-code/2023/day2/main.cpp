#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream in("input.txt");
  string line;

  while (getline(in, line)) {
    cout << line << endl;
  }

  in.close();

  return 0;
}
