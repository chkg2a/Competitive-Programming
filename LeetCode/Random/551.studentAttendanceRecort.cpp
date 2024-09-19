#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool checkRecord(string s) {
  unordered_map<char, int> umap;
  int lateCount = 0, maxLate = 0;
  for(auto x : s){
    umap[x]++;
    if(x == 'L'){
      lateCount++;
    }else{
      maxLate = max(maxLate,lateCount);
      lateCount = 0;
    }
  }
  if(umap['A'] < 2 && max(maxLate,lateCount) < 3){
    return true;
  };
  return false;
} 

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  string s = "AA";
  cout << checkRecord(s);

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
