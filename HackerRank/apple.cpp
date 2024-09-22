#include <iostream>
#include <vector>

using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
  int noOfApplesLand = 0; 
  int noOfOrangesLand = 0; 
  for(auto apple: apples){
    if(apple+a >= s && apple+a <= t){
      noOfApplesLand++;
    }
  }
  for(auto orange: oranges){
    if(orange+b >= s && orange+b <= t){
      noOfOrangesLand++;
    }
  }
  // cout << noOfApplesLand << endl << noOfOrangesLand;
}

int main (int argc, char *argv[]) {
  vector<int> apples = {2,3,-4};
  vector<int> oranges = {3,-2,-4};
  countApplesAndOranges(7,10,4,12,apples,oranges);
  return 0;
}
