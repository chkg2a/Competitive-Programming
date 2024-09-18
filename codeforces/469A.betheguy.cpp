#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  string s;
  cin.ignore();
  getline(cin, s);
  stringstream ss(s);

  unordered_map<int, int> umap;
  int X, Y;
  ss >> X;

  int num;
  while (ss >> num) {
    umap[num]++;
  }
  cin.ignore();
  getline(cin, s);
  stringstream sx(s);

  ss >> Y;
  while (sx >> num) {
    umap[num]++;
  }
  int cond = 0;
  for (int i = 0; i < n; i++) {
    cout << umap.count(i);
    /*if (umap.count(i)) {*/
    /*  cond = 1;*/
    /*}*/
  }
  if (cond) {

    cout << "Oh, my keyboard!";
  } else {
    cout << "I become the guy.";
  }

  return 0;
}
