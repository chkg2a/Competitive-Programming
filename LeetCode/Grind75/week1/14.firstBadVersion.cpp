#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int bad = 10;
int versionNumber = 20;

bool isBadVersion(int version){
  return version>= bad;
}

class Solution {
public:
    int firstBadVersion(int n) {
       int first = 1; 
       int last = n;
       while(first < last){
         int mid = first + (last - first) /2;
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
  cout << sol.firstBadVersion(versionNumber);

  return 0;
}
