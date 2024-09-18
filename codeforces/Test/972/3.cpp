#include <iostream>
#include <cmath>  // For abs function
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;  // n (number of cells), x and y (positions of teachers)

        int teacher[2];  // Positions of two teachers
        cin >> teacher[0] >> teacher[1];

        int studentPos;
        cin >> studentPos;  // Position of the student (David)

        // Calculate the distance between David and each teacher
        int dist1 = abs(studentPos - teacher[0]);
        int dist2 = abs(studentPos - teacher[1]);

        // The answer is the maximum of these two distances
        cout << max(dist1, dist2) << endl;
    }

    return 0;
}

