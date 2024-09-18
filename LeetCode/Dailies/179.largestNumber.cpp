#include <bits/stdc++.h>
using namespace std;

string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        // Convert each integer to a string
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }

        // Sort strings based on concatenated values
        sort(numStrings.begin(), numStrings.end(),
             [](string &a, string &b) { return a + b > b + a; });

        // Handle the case where the largest number is zero
        if (numStrings[0] == "0") return "0";

        // Concatenate sorted strings to form the largest number
        string largestNum;
        for (string &numStr : numStrings) {
            largestNum += numStr;
        }

        return largestNum; 
}

int main(int argc, char *argv[]) {
  auto start = std::chrono::high_resolution_clock::now();

  vector<int> nums = {3,30,34,5,9};
  cout << largestNumber(nums);

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
