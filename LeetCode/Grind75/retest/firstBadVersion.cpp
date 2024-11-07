// 1:25
#include <bits/stdc++.h>
using namespace std;

int bad = 17;
int versionNumber = 20;

bool isBadVersion(int version){
  return version>= bad;
}

class Solution {
public:
    int firstBadVersion(int n) {
      int first = 0;
      int last = n;
      while(first < last){
        int mid = first + (last - first) / 2;
        if(isBadVersion(mid)){
          last = mid;
        }else{
          first = mid + 1;
        }
      }
      return first;
    }
};


int main () {
  Solution sol;
  cout << sol.firstBadVersion(versionNumber); // 10

  return 0;
}
