#include <iostream>
#include <chrono>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  vector<int> output;    
  unordered_map<int,int> numberStorage;
  for(auto x : nums){
    numberStorage[x]++;
  }
  vector<pair<int,int>> v;
  for(auto it: numberStorage){
    v.push_back(make_pair(it.second,it.first));
  }
  sort(v.rbegin(),v.rend());
  for(int i = 0; i < v.size() && k!=0; i++){
    output.push_back(v[i].second);
    k--;
  }
  return output;
}

int main (int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  cout << "Output : ";

  srand(time(0));
  vector<int> nums;
  for(int i = -1000; i < 1000;i++){
    int val = rand()/100;
    nums.push_back(val);
  }
  int target = rand()/100;
  
  for(auto x: topKFrequent(nums, target)){
    cout << x << " ";
  }
  

  std::cout <<  std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(end - start); 
  std::cout << "Execution time: " << duration_s.count() << " seconds " << std::endl;
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); 
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds " << std::endl;
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); 
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";


  return 0;
}
