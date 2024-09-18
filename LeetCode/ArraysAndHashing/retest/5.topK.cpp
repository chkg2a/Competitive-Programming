#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  vector<int> output;
  unordered_map<int,int> umap;
  vector<pair<int,int>> sorted;

  for(auto x : nums){
    umap[x]++;
  }
  
  for(auto x : umap){
    sorted.push_back(x);
  }

  sort(sorted.begin(),sorted.end());

  for(auto x : sorted){
    if(x.second > k){
      output.push_back(x.first);
    }
  }

  return output;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<int> nums = {4,4,5,5,5,8,8,8,8};
  int k = 2;
  for(auto x : topKFrequent(nums, k)){
    cout << x << " ";
  }

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds " << std::endl;
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds " << std::endl;
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
