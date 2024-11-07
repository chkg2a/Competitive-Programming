/* 383. Ransom Note
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*/
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
          if(arr[c - 'a'] < 0){
            return false;
          }
        }
        return true;
    }
};

int main () {
  string ransomNote = "a", magazine = "b"; // 0
  /*string ransomNote = "aa", magazine = "aab"; // 1*/
  Solution sol;
  cout << sol.canConstruct(ransomNote, magazine);

  return 0;
}
