#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    unordered_map<int,int> umap;
    vector<int> copyArr = arr;
    vector<int> output;
    output.reserve(4096);
    sort(copyArr.begin(),copyArr.end());
    for(int i = 0; i < arr.size(); i++){
      umap[arr[i]] = i;
    }
    int arr_size = arr.size();
    int rank = 1;
    int i = 0;
    while(arr_size-- || arr_size == 1){
      if(umap[copyArr[i]] != umap[copyArr[i+1]]){
        rank++; 
      }
      output[umap[arr[i]]] = rank;
      i++;
    }
    return output;
  }
};

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  Solution s;
  vector<int> arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};
  for (auto x : s.arrayRankTransform(arr)) {
    cout << x << " ";
  };

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s =
      std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds "
            << std::endl;
  auto duration_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds "
            << std::endl;
  auto duration_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
