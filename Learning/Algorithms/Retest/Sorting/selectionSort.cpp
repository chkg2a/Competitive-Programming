#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], const int & size){
}

void displayArr(int arr[], const int & size){
  for(int i = 0; i < size; i++){
    cout << arr[i] << ' ';
  }
  cout << endl;
}

int main () {
  const int size = 6;
  int arr[size] = {6,5,3,2,1,4};

  displayArr(arr,size);
  selectionSort(arr, size);
  displayArr(arr,size);

  return 0;
}
