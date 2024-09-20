#include <bits/stdc++.h>
using namespace std;

int kmp(const string &txt, const string &patt) {
  string newString = patt + '#' + txt;
  vector<int> pi(newString.length(), 0);
  int i = 1, k = 0;
  while (i < newString.length()) {
    if (newString[i] == newString[k]) {
      k++;
      pi[i] = k;
      i++;
    } else {
      if (k > 0) {
        k = pi[k - 1];
      } else {
        pi[i] = 0;
        i++;
      }
    }
  }
  return pi.back();
}

string shortestPalindrome(string s) {
  int count = kmp(string(s.rbegin(), s.rend()), s);
  return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  string x = "aacecaaa";
  cout << shortestPalindrome(x);
  /*shortestPalindrome(x);*/

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s =
      std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds "
            << std::endl;
  auto duration_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds "
            << std::endl;
  auto duration_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
