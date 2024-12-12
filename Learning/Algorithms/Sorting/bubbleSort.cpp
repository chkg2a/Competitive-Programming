#include<chkg2a/fn_utility.h>

void bubbleSort(int * arr, const int & size){
  for(int i =0 ; i < size - 1; i++){
    bool swapped = false;
    for(int j = 0; j < size - 1 - i; j++){
      if(arr[j] > arr[j+1]){
        swapped = true;
        arr[j] ^= arr[j+1];
        arr[j+1] ^= arr[j];
        arr[j] ^= arr[j+1];
      }
    }
    if(!swapped){
      return;
    }
  }
}

int main(){
  const int size = 7;
  int arr[size] = {5,1,6,9,10,7,2};
  chk::display_arr(arr,size);
  bubbleSort(arr,size);
  chk::display_arr(arr,size);
}
