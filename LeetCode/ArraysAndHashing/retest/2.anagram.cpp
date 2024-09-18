#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  if(s == t){
    return true;
  }
  return false;
} 

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  string s = "racecar";
  string t = "carrace";

  cout << isAnagram(s,t);

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
