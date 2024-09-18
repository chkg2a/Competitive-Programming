#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  int temp = t;
  int output[t];
  while (t != 0) {
    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);
    stringstream ss(s);
    int arr[n];
    int i = 0;
    int num;
    while (ss >> num) {
      arr[i] = num;
      i++;
    }
    num = 0;
    for (int j = 0; j < n; j++) {
      if (j % 2 != 0) {
        num -= arr[j];
      } else {
        num += arr[j];
      }
    }
    output[temp - t] = num;
    t--;
  }
  for (int i = 0; i < temp; i++) {
    cout << output[i] << endl;
  }

  return 0;
}
