#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
  }
};

int main() {
  // 2 2 2
  // 2 2 0
  // 2 0 1
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  // 2 2 2
  // 2 2 2
  /*vector<vector<int>> image = {{0, 0, 0}, {0, 0, 0}};*/
  int sr = 1, sc = 1, color = 2;
  Solution sol;
  for (vector<int> i : sol.floodFill(image, sr, sc, color)) {
    for (int x : i) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}
