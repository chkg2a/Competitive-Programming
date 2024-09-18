#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> output;
  vector<int> prefixArr;
  vector<int> postfixArr;
  
  int prefix = 1;
  int postfix = 1;

  prefixArr.push_back(prefix);
  for(int i = 0; i < nums.size(); i++){
    prefix *= nums[i];
    prefixArr.push_back(prefix);
  }

  postfixArr.push_back(postfix);
  for(int i = nums.size()-1; i >= 0; i--){
    postfix *= nums[i];
    postfixArr.push_back(postfix);
  }

  std::reverse(postfixArr.begin(),postfixArr.end());
  for(int i = 0; i < nums.size(); i++){
    output.push_back(prefixArr[i] * postfixArr[i+1]);
  }
  return output;
}

int main (int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  cout << "Output : ";
  srand(time(0));

  vector<int> nums = {-1,0,1,2,3};
  // vector<int> nums = {1,2,3,4};
  for(auto x : productExceptSelf(nums)){
    cout << x << endl;
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
