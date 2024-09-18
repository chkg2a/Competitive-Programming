#include "sll.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

List reverseList(List head) {
  List curr = head;
  List prev = NULL;
  List temp;
  while (curr != NULL) {
    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();
  cout << "Output : ";
  List l1 = init();
  addRear(l1, 1);
  addRear(l1, 2);
  addRear(l1, 3);
  cout << "Before : ";
  display(l1);
  cout << "After : ";
  List l2 = reverseList(l1);
  display(l2);

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s =
      std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds "
            << std::endl;
  auto duration_ms =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds "
            << std::endl;
  auto duration_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";

  return 0;
}
