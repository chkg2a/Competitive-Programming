#include <bits/stdc++.h>
using namespace std;

int linearSearch(const int arr[], const int &size, const int &toSearch) {
}

int main() {
  const int size = 10000;
  int arr[size];
  for(int i = 0; i < size; i++){
    arr[i] = i;
  }
  int toSearch = 92;
  cout << linearSearch(arr, size, toSearch);

  return 0;
}
