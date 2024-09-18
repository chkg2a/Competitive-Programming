#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  int F = 0; 
  int R = numbers.size()-1;
  while(1){
    int sum = numbers[F] + numbers[R];
    if(sum > target){
      R--;
    }else if(sum < target){
      F++;
    }else{
      return {F+1,R+1};
    }
  }
  return {};
}
  

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  vector<int> nums = {1,3,4,5,7,8,10,11};
  int target = 9;

  for(auto x : twoSum(nums,target)){
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
