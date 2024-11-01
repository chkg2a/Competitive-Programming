/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int minPrice = INT_LEAST32_MAX, maxProfit = 0;
      for(auto price : prices){
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
      }
      return maxProfit;
    }
    /*int maxProfit(vector<int>& prices) {*/
    /*  int lowestPrice = 0, highestPrice = 0, maxProfit, highest; */
    /*  highest = prices[highestPrice];*/
    /*  while(highestPrice != (int)prices.size()){*/
    /*    if(prices[lowestPrice] > prices[highestPrice]){*/
    /*      lowestPrice = highestPrice;*/
    /*      highest = prices[lowestPrice];*/
    /*    }*/
    /*    highestPrice++;*/
    /*    highest = max(highest, prices[highestPrice]);*/
    /*    maxProfit = max(maxProfit,highest - prices[lowestPrice]);*/
    /*  }*/
    /*  return maxProfit;*/
    /*}*/
};

int main () {
  Solution sol;
  vector<int> prices = {2,4,1};
  cout << sol.maxProfit(prices);

  return 0;
}
