#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
private:
  set<pair<int, int>> calendar;

public:
  bool book(int start, int end) {
    const pair<int, int> event{start, end};
    const auto nextEvent = calendar.lower_bound(event);
    if (nextEvent != calendar.end() && nextEvent->first < end) {
      return false;
    }

    if (nextEvent != calendar.begin()) {
      const auto prevEvent = prev(nextEvent);
      if (prevEvent->second > start) {
        return false;
      }
    }

    calendar.insert(event);
    return true;
  }
};

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  MyCalendar * myCalendar = new MyCalendar();
  cout << myCalendar->book(10, 20) << endl;
  cout << myCalendar->book(15, 25) << endl;
  cout << myCalendar->book(20, 30) << endl;

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
