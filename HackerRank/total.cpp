#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int getTotalX(vector<int> a, vector<int> b) {
  int tot = 0;
  int num = 1;
  int totalLen = a.size() + b.size();
  vector<int> x;
  vector<int> y;
  vector<int> z;
  vector<int> r;
  for (long unsigned int i = 1; i < 101; i++) {
    for (auto num : a) {
      if (i % num == 0) {
        x.push_back(i);
      }
    }
    for (auto num : b) {
      if (num % i == 0) {
        y.push_back(i);
      }
    }
  }
  for (auto num : x) {
    z.push_back(num);
  }
  for (auto num : y) {
    z.push_back(num);
  }
  unordered_map<int, int> numz;
  for (auto num : z) {
    numz[num]++;
  }
  for (auto h : numz) {
    if (h.second == totalLen){
      r.push_back(h.first);
    }
  }
  tot = r.size();
  return tot;
}

int main(int argc, char *argv[]) {
  vector<int> a = {2, 4};
  vector<int> b = {16, 32, 96};
  getTotalX(a, b);
  return 0;
}
