#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

string preProcessor(string s) {
  string output = "";
  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i])) {
      output += s[i];
    } else {
      if (s[i] == 'o') {
        if (s[i + 1] == 'n' && s[i + 2] == 'e') {
          output += '1';
        }
      } else if (s[i] == 't') {
        if (s[i + 1] == 'w' && s[i + 2] == 'o') {
          output += '2';

        } else if (s[i + 1] == 'h' && s[i + 2] == 'r' && s[i + 3] == 'e' &&
                   s[i + 4] == 'e') {
          output += '3';
        }
      } else if (s[i] == 'f') {
        if (s[i + 1] == 'o' && s[i + 2] == 'u' && s[i + 3] == 'r') {
          output += '4';

        } else if (s[i + 1] == 'i' && s[i + 2] == 'v' && s[i + 3] == 'e') {
          output += '5';
        }
      } else if (s[i] == 's') {
        if (s[i + 1] == 'i' && s[i + 2] == 'x') {
          output += '6';

        } else if (s[i + 1] == 'e' && s[i + 2] == 'v' && s[i + 3] == 'e' &&
                   s[i + 4] == 'n') {
          output += '7';
        }
      } else if (s[i] == 'e') {
        if (s[i + 1] == 'i' && s[i + 2] == 'g' && s[i + 3] == 'h' &&
            s[i + 4] == 't') {
          output += '8';
        }
      } else if (s[i] == 'n') {
        if (s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'e') {
          output += '9';
        }
      } else if (s[i] == 'z') {
        if (s[i + 1] == 'e' && s[i + 2] == 'r' && s[i + 3] == 'o') {
          output += '0';
        }
      }
    }
  }
  cout << s << "," << output << endl;
  return output;
}

int sumFunc(string s) {
  int F, R;
  int encounter = 0;
  for (auto x : s) {
    if (isdigit(x)) {
      R = (int)x - '0';
      if (encounter == 0) {
        F = (int)x - '0';
      }
      encounter++;
    }
  }
  return (F * 10) + R;
}

int main() {
  ifstream iFile("input.txt");
  if (!iFile) {
    cerr << "Unable to launch input.txt" << endl;
    return 1;
  }
  string line;
  int sum = 0;

  while (getline(iFile, line)) {
    sum += sumFunc(preProcessor(line));
  }
  iFile.close();
  cout << sum << endl;

  return 0;
}
