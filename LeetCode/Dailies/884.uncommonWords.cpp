#include <bits/stdc++.h>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2){
  unordered_map<string,int> umap;
  stringstream s1s(s1);
  stringstream s2s(s2);
  string temp;
  while(s1s >> temp){
    umap[temp]++;
  }
  while(s2s >> temp){
    umap[temp]++;
  }
  vector<string> ans;
  for(auto x : umap){
    if(x.second < 2){
      ans.push_back(x.first);
    }
  }
  return ans;
}

int main (int argc, char *argv[]) {
  string s1 = "this apple is sour";
  string s2 = "this apple is sweet";

  for(auto x : uncommonFromSentences(s1,s2)){
    cout << x << " ";
  }

  return 0;
}
