#include<iostream>
using namespace std;

int* rotateArr(int arr[],const int & size, const int & k){
  int rotateBy = k % size; 
  int newArr[size] = {0};
  for(int i = 0; i < size; i++){
    newArr[(i+rotateBy)%size] = arr[i];
  }
  for(int i = 0; i < size; i++){
    arr[i] = newArr[i];
  }
  return arr;
}

void displayArr(const int arr[],const int & size){
  for(int i = 0; i < size; i++){
    cout << arr[i] << ' ';
  }
  cout << endl;
}

int main(){
  const int size = 7;
  const int k = 3;
  int arr[size] = {1,2,3,4,5,6,7};
  cout << "Before rotating Arr : ";
  displayArr(arr,size);
  rotateArr(arr,size,k);
  cout << "After rotating Arr : ";
  displayArr(arr,size);
}
