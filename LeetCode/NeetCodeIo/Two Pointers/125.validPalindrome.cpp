#include <cctype>
#include <iostream>
#include <chrono>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool isPalindrome(string s){
  int l = 0;
  int r = s.length();
  
  while(l < r){
    while(!isalnum(s[l])){
      l++;
    };
    while(!isalnum(s[r])){
      r--;
    }
    if(tolower(s[l]) != tolower(s[r])){
      return false;
    }
    l++;
    r--;
  }
  return true;
}

int main (int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  cout << "Output : ";
  srand(time(0));

  string s = "A man, a plan, a canal: Panama";
   
  cout << isPalindrome(s);

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
