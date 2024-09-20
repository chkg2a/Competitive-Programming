#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isHappy(int n) {
  int l = 0, sum = 0;
  while (n > 0) {
    l = n % 10;
    sum = sum + (l * l);
    n = n / 10;
  }
  if (sum == 1)
    return true;
  else if (sum == 7)
    return true;
  else if (sum < 10)
    return false;
  else
    return isHappy(sum);
}

int main(int argc, char *argv[]) {
  int n = 19;
  printf("%d", isHappy(n));
  return EXIT_SUCCESS;
}
