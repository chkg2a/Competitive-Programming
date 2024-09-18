#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
  stack<char> stk;
  unordered_map<char,char> umap ={
    {'}','{'},
    {']','['},
    {')','('}
  };
  for(auto x : s){
    if(umap.count(x)){
      if(!stk.empty() && stk.top() == umap[x]){
        stk.pop();
      }else{
        return false;
      }
    }else{
      stk.push(x);
    }
  }
  if(stk.empty()){
    return true;
  }
  return false;
} 

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  string s = "([{}])";
  cout << isValid(s);

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
