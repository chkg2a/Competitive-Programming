#include<chkg2a/fn_utility.h>

void merge(int * arr, const int left, const int mid, const int right){
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int * L = new int(n1);
  int * R = new int(n2);

  for(int i = 0; i < n1; i++)
    L[i] = arr[i+left];
  for(int i = 0; i < n2; i++)
    R[i] = arr[i+mid+1];

  int i = 0, j = 0, k = left;

  while(i < n1 && j < n2){
    if(L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }

  while(i < n1)
    arr[k++] = L[i++];
  while(j < n2)
    arr[k++] = R[j++];

  delete L;
  delete R;
}

void mergeSort(int * arr,const int left, const int right){
  if(left < right){
    int mid = (left + right) /2;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
  }
}

int main(){
  const int size = 7;
  int arr[size] = {5,1,6,9,10,7,2};
  chk::display_arr(arr,size);
  mergeSort(arr,0,size-1);
  chk::display_arr(arr,size);
}
