#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    // Store the number of bookings at each point.
    map<int, int> bookingCount;
    // The maximum number of overlapped bookings allowed.
    int maxOverlappedBooking;

    MyCalendarTwo() { maxOverlappedBooking = 2; }

    bool book(int start, int end) {
        // Increase and decrease the booking count at the start and end
        // respectively.
        bookingCount[start]++;
        bookingCount[end]--;

        int overlappedBooking = 0;
        // Find the prefix sum.
        for (pair<int, int> bookings : bookingCount) {
            overlappedBooking += bookings.second;

            // If the number of bookings is more than 2, return false.
            // Also roll back the counts for this booking as we won't add it.
            if (overlappedBooking > maxOverlappedBooking) {
                bookingCount[start]--;
                bookingCount[end]++;

                // Remove the entries from the map to avoid unnecessary
                // iteration.
                if (bookingCount[start] == 0) {
                    bookingCount.erase(start);
                }
                if (bookingCount[end] == 0) {
                    bookingCount.erase(end);
                }

                return false;
            }
        }

        return true;
    }
};
  

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  MyCalendarTwo calendar;
  cout << calendar.book(10, 20);
  cout << calendar.book(50, 60);
  cout << calendar.book(10, 40);
  cout << calendar.book(5, 15);
  cout << calendar.book(5, 10);
  cout << calendar.book(25, 55);

  std::cout << std::endl;
  auto end = std::chrono::high_resolution_clock::now();
  auto duration_s = std::chrono::duration_cast<std::chrono::seconds>(end - start);
  std::cout << "Execution time: " << duration_s.count() << " seconds " << std::endl;
  auto duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds " << std::endl;
  auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
  std::cout << "Execution time: " << duration_ns.count() << " nanoseconds ";
  return 0;
}
