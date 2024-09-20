#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>
#include <string>
using namespace std;

string addEachDigit(string s) {
  int sum = 0;
  for (int i = 0; i < s.size(); i++) {
    sum += s[i] - '0';
  }
  return to_string(sum);
}

int getLucky(string s, int k) {
  string newStr;
  for (int i = 0; i < s.size(); i++) {
    newStr += to_string(s[i] - 'a' + 1);
  }
  string finalint = newStr;
  while(k--){
    finalint = addEachDigit(finalint);
  }
  return stoi(finalint);
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  string s = "iiii";
  int k = 1;

  cout << getLucky(s, k);

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
