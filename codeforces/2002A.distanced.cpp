#include <iostream>
#include <algorithm>
#include <chrono>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  int t;
  cin >> t;

  int p,x,y;

  

  for(int i = 0; i < t; ++i) {

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
