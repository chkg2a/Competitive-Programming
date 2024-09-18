#include <iostream>

int main(int argc, char *argv[]) {
  int in;
  std::cin >> in;
  std::string s[in];
  for (int i = 0; i < in; i++) {
    std::cin >> s[i];
  }

  for (int i = 0; i < in; i++) {
    if (s[i].size() <= 10) {
      std::cout << s[i] << std::endl;
      continue;
    }
    int count = -2;
    for (auto x : s[i]) {
      count++;
    }
    std::cout << s[i][0] << count << s[i][s[i].size() - 1] << std::endl;
  }

  return 0;
}
