#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  //0ms, O(n), O(n)
  bool isCircularSentence(string sentence) {
    stringstream ss(sentence);
    string word;
    vector<string> words;
    while (ss >> word) {
      words.push_back(word);
    }
    int n = words.size();

    char last = words[n - 1].back();
    for (auto x : words) {
      if (last != x.front())
        return false;
      last = x.back();
    }
    return true;
  }
  //3ms, O(n), O(1)
  /*bool isCircularSentence(string sentence) {*/
  /*  for (int i = 0; i < sentence.size(); ++i)*/
  /*    if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])*/
  /*      return false;*/
  /*  return sentence[0] == sentence[sentence.size() - 1];*/
  /*}*/

  // 113 ms XD
  /*bool isCircularSentence(string sentence) {*/
  /*  int encounteredNextWord = 0;*/
  /*  char firstLetter = 0;*/
  /*  char lastLetter = -1;*/
  /*  for (int i = 0; i < sentence.size(); i++) {*/
  /*    if (encounteredNextWord) {*/
  /*      encounteredNextWord = 0;*/
  /*    }*/
  /*    if (sentence[i] == ' ') {*/
  /*      lastLetter = sentence[i-1];*/
  /*      firstLetter = sentence[i+1];*/
  /*      encounteredNextWord = 1;*/
  /*    }*/
  /*    cout << firstLetter << lastLetter << endl;*/
  /*    if (sentence[0] != sentence[sentence.size() - 1] || encounteredNextWord
   * &&*/
  /*        firstLetter != lastLetter) {*/
  /*      return false;*/
  /*    }*/
  /*  }*/
  /*  return true;*/
  /*}*/
};

int main() {
  string sentence = "leetcode exercises sound delightful";
  /*string sentence = "Leetcode is cool";*/
  /*string sentence = "leetcode";*/
  Solution sol;
  cout << sol.isCircularSentence(sentence);

  return 0;
}
