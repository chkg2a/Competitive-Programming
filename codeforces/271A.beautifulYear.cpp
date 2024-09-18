#include <iostream>
#include <unordered_map>
using namespace std;

int computeYear(int year){
  int output;
  for(int i = year+1; i <= 10000; i++){
    string form = to_string(i);
    unordered_map<char, int> umap;
    umap[form[0]]++;
    umap[form[1]]++;
    umap[form[2]]++;
    umap[form[3]]++;
    int cond = 0;
    for(int i = 0; i < 4; i++){
      if(umap[form[i]] > 1){
        cond = 1;
      }
    }
    if(!cond){
      return i;
    }
  }
  return year;
}

int main(int argc, char *argv[]) {
  int year;
  cin >> year;
  cout << computeYear(year);

  return 0;
}
