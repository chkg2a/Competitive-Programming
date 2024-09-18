#include <iostream>
#include <algorithm>
#include <chrono>
#include <limits>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int findMinDifference(vector<string> & timePoints){
  vector<int> mins(timePoints.size());
  for(int i = 0; i < timePoints.size();i++){
    string time = timePoints[i];
    int h = stoi(time.substr(0,2));
    int m = stoi(time.substr(3));
    mins[i] = h * 60 + m;
  }
  sort(mins.begin(),mins.end());
  int ans = numeric_limits<int>::max();
  for(int i = 0; i < mins.size() - 1; i++){
    ans = min(ans, mins[i + 1] - mins[i]);
  }
  return min(ans,24 * 60 - mins[mins.size() - 1] + mins[0]);
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<string> timeS = {"00:00", "23:59"};

  cout << findMinDifference(timeS);
  /*findMinDifference(timeS);*/
  
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
