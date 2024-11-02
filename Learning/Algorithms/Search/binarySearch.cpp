#include <bits/stdc++.h>
using namespace std;

int binarySearch(const int arr[], const int &size, const int &toSearch) {
  int low = 0;
  int mid;
  int high = size - 1;
  int iteration = 0;
  while (low <= high) {
    iteration++;
    mid = (low + high) / 2;
    cout << iteration << " = Low : " << arr[low] << ", Mid : " << arr[mid]
         << ", High : " << arr[high] << endl;
    if (arr[mid] < toSearch) {
      low = mid + 1;
    } else if (arr[mid] > toSearch) {
      high = mid - 1;
    } else {
      return 1;
    }
  }
  return 0;
}

int main() {
  const int size = 10000;
  int arr[size];
  for(int i = 0; i < size; i++){
    arr[i] = i;
  }
  int toSearch = 92;
  cout << binarySearch(arr, size, toSearch);

  return 0;
}
