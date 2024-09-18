#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases

    string vowels = "aeiou";  // Base pattern of vowels
    
    while (t--) {
        int n;
        cin >> n;  // Length of the string
        
        // Construct the string by repeating the vowel pattern and trimming to length n
        string result = "";
        for (int i = 0; i < n; ++i) {
            result += vowels[i % 5];  // Repeat the "aeiou" pattern
        }
        
        cout << result << endl;  // Output the result for this test case
    }

    return 0;
}
