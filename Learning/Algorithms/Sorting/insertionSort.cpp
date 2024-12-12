#include<chkg2a/fn_utility.h>

void insertionSort(int * arr, const int & size){
  for(int i = 0; i < size; i++){
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

int main(){
  const int size = 7;
  int arr[size] = {5,1,6,9,10,7,2};
  chk::display_arr(arr,size);
  insertionSort(arr,size);
  chk::display_arr(arr,size);
}
