//2:06

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int arr[26] = {0};
    for(char c : magazine){
      arr[c - 'a']++;
    }
    for(char c : ransomNote){
      arr[c - 'a']--;
      if(arr[c-'a'] < 0){
        return 0;
      }
    }
    return 1;
  }
};

int main() {
  /*string ransomNote = "a", magazine = "b"; // 0*/
  string ransomNote = "aa", magazine = "aab"; // 1
  Solution sol;
  cout << sol.canConstruct(ransomNote, magazine);

  return 0;
}
