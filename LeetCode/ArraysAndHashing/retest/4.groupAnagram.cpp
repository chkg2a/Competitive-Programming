#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<string> sorted;
  unordered_map<string,vector<string>> umap;
  vector<vector<string>> output;

  for(auto x : strs){
    string temp = x;
    sort(temp.begin(), temp.end());
    sorted.push_back(temp);
  }

  for(int i = 0; i < strs.size(); i++){
    umap[sorted[i]].push_back(strs[i]);
  }
  for(auto x : umap){
    vector<string> st;
    for(auto y : x.second){
      st.push_back(y);
    }
    output.push_back(st);
  }
  return output;
}
  

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<string> strs = {"act","pots","tops","cat","stop","hat"};
  for(auto group : groupAnagrams(strs)){
    for(auto str : group){
      cout << str << " ";
    }
    cout << endl;
  }

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
