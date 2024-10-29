/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include <bits/stdc++.h>
using namespace std;

int pick = 6;

int guess(int num) {
  if (num > pick) {
    return -1;
  } else if (num < pick) {
    return 1;
  } else {
    return 0;
  }
}

class Solution {
public:
  int guessNumber(int n) {
    int start = 1;
    int end = n;
    while (start <= end) {
      int mid = start + (end - start) / 2;

      if (guess(mid) == -1) {
        end = mid;
      } else if (guess(mid) == 1) {
        start = mid + 1;
      } else {
        return mid;
      }
    }
    return 0;
  }
};

int main(int argc, char *argv[]) {
  Solution sol;
  cout << sol.guessNumber(10);
  return 0;
}
