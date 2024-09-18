#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 2147483647
using namespace std;

// Function to find the closest teacher using binary search
int findClosestTeacher(const vector<int>& teachers, int studentPos) {
    // Binary search to find the closest position
    auto it = lower_bound(teachers.begin(), teachers.end(), studentPos);
    
    int minDistance = INT_MAX;
    
    // Check the teacher to the right of the studentPos (if exists)
    if (it != teachers.end()) {
        minDistance = min(minDistance, abs(*it - studentPos));
    }
    
    // Check the teacher to the left of the studentPos (if exists)
    if (it != teachers.begin()) {
        --it;
        minDistance = min(minDistance, abs(*it - studentPos));
    }
    
    return minDistance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;  // n (number of cells), m (number of teachers), q (number of queries)
        
        vector<int> teachers(m);
        for (int i = 0; i < m; ++i) {
            cin >> teachers[i];  // Teachers' positions
        }
        
        // Sort the teachers' positions to allow binary search
        sort(teachers.begin(), teachers.end());
        
        while (q--) {
            int studentPos;
            cin >> studentPos;  // Position of David (the student)
            
            // Find the minimum distance to the closest teacher
            int result = findClosestTeacher(teachers, studentPos);
            cout << result << "\n";
        }
    }
    
    return 0;
}
