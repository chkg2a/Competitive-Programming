#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*vector<int> dailyTemperatures(vector<int> &temperatures) {*/
/*  vector<int> output;*/
/*  for (int i = 0; i < temperatures.size(); i++) {*/
/*    int count = 0;*/
/*    for (int j = i; j < temperatures.size(); j++) {*/
/*      if (temperatures[i] < temperatures[j]) {*/
/*        break;*/
/*      } else if (j == temperatures.size() - 1) {*/
/*        count = 0;*/
/*      } else {*/
/*        count++;*/
/*      }*/
/*    }*/
/*    output.push_back(count);*/
/*  }*/
/*  return output;*/
/*}*/
vector<int> dailyTemperatures(vector<int> &temperatures) {
  vector<int> output(temperatures.size(), 0);
  vector<pair<int, int>> stk;
  for (int i = 0; i < temperatures.size(); i++) {
    while (!stk.empty() && temperatures[i] > stk.back().first) {
      int st = stk.back().first;
      int stI = stk.back().second;
      output[stI] = (i - stI);
      stk.pop_back();
    }
    stk.push_back(make_pair(temperatures[i], i));
  }
  return output;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  vector<int> temps = {30, 38, 30, 36, 35, 40, 28};
  /*vector<int> temps = {22, 21, 20};*/
  for (auto x : dailyTemperatures(temps)) {
    cout << x << ',';
  }

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s =
      std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds "
            << std::endl;
  auto duration_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds "
            << std::endl;
  auto duration_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
