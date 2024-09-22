#include <iostream>
#include <vector>

using namespace std;

vector<int> roundUp(vector<int> grades) {
  vector<int> c;

  for (auto grade : grades) {
    int divisor = (grade/5)*5 + 5;
    if (grade < 38) {
      c.push_back(grade);
    }
    else if (divisor - grade > 2){
      c.push_back(grade);
    }
    else {
      c.push_back(divisor);
    }
  }
  return c;
}

int main(int argc, char *argv[]) { 
  vector<int> grades = {73,67,38, 35};
  for (auto num :roundUp(grades)){
    cout << num << endl;
  }
  return 0; 
}
