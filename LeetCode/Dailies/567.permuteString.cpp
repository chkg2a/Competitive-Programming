#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static inline array<int, 26> count(string& s, int l, int r){
        array<int, 26> freq={0};
        for(int i=l; i<=r; i++)
            freq[s[i]-'a']++;
        return freq;
    }

    static bool checkInclusion(string& s1, string& s2) {
        const int n1=s1.size(), n2=s2.size();
        if (n2<n1) return 0;
        auto freq1=count(s1, 0, n1-1);
        auto freq2=count(s2, 0, n1-1);
        if (freq1==freq2) return 1;
        for(int l=1, r=n1; r<n2; r++, l++){
            freq2[s2[l-1]-'a']--;
            freq2[s2[r]-'a']++;
            if (freq2== freq1) return 1;
        }
        return 0;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}(); 

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  string s1 = "ab";
  string s2 = "eidbaooo";
  cout << Solution::checkInclusion(s1, s2) << endl;

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds " << std::endl;
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds " << std::endl;
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
