#include<chkg2a/fn_utility.h>

void selectionSort(int * arr, const int & size){
  for(int i =0; i < size; i++){
    int maxI = i;
    for(int j =i+1; j < size +1; j++){
      if(arr[maxI] > arr[j]){
        arr[j] ^= arr[maxI];
        arr[maxI] ^= arr[j];
        arr[j] ^= arr[maxI];
      }
    }
  }
}

int main(){
  const int size = 7;
  int arr[size] = {5,1,6,9,10,7,2};
  chk::display_arr(arr,size);
  selectionSort(arr,size);
  chk::display_arr(arr,size);
}
