#include <iostream>

int main(int argc, char *argv[]) {
  int in;
  std::cin >> in;
  if (in % 2 == 1 || in == 2 || in == 0) {
    std::cout << "NO";
  } else {
    std::cout << "YES";
  }

  return 0;
}
