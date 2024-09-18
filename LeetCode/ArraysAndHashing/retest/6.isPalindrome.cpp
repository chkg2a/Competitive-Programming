#include <bits/stdc++.h>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
  string newS;
  for(char c : s){
    if(isalnum(c)){
      newS.push_back(tolower(c));
    }
  }
  int cond = 0;
  for(int i = 0; i <= newS.size(); i++){
    if(newS[i] != newS[newS.size()-i-1]){
      cond = 1;
    }
  }
  if(cond){
    return false;
  }
  return true; 
} 

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  string s = "Was it a car or a cat I saw?";
  cout << isPalindrome(s);

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
