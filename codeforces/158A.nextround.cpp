#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {

  string fLine;
  getline(cin, fLine);

  stringstream fStream(fLine);
  int n, k;
  fStream >> n >> k;

  string sLine;
  getline(cin, sLine);

  int *arr = new int[n];

  stringstream ss(sLine);
  int num, index = 0;

  while (ss >> num) {
    arr[index++] = num;
  }

  int count = 0;

  for (int i = 0; i < n; i++) {

    if (arr[i] >= arr[k - 1] && arr[i] > 0) {
      count++;
    }
  }

  cout << count << endl;

  delete[] arr;

  return 0;
}

