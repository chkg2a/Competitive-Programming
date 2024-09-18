#include <iostream>
#include<cmath>
using namespace std;

int main (int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int d1 = abs(z - x);
    int d2 = abs(z - y);

    int result = min(d1,d2);
    cout << result << endl;
  }

  return 0;
}
