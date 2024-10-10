#include <bits/stdc++.h>
using namespace std;

/*class Solution {*/
/*public:*/
/*  int minAddToMakeValid(string s) {*/
/*    stack<char> stk;*/
/*    unordered_map<char, char> umap = {*/
/*        {')', '('},*/
/*        {']', '['},*/
/*        {'}', '{'},*/
/*    };*/
/*    int output = 0;*/
/*    for (char c : s) {*/
/*      if (umap.count(c)) {*/
/*        if (!stk.empty() && stk.top() == umap[c]) {*/
/*          stk.pop();*/
/*        } else {*/
/*          output++;*/
/*        }*/
/*      } else {*/
/*        stk.push(c);*/
/*      }*/
/*    };*/
/*    while (!stk.empty()) {*/
/*      output++;*/
/*      stk.pop();*/
/*    }*/
/*    return output;*/
/*  }*/
/*};*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;

        int minAddsRequired = 0;
        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else {
                // If open bracket exists, match it with the closing one
                // If not, we need to add a open bracket.
                openBrackets > 0 ? openBrackets-- : minAddsRequired++;
            }
        }

        // Add the remaining open brackets as closing brackets would be
        // required.
        return minAddsRequired + openBrackets;
    }
};

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  Solution sol;
  string s = "(((";
  cout << sol.minAddToMakeValid(s);

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
