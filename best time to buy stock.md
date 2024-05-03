[121\. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

Solved

Easy

Topics

Companies

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i<sup>th</sup>` day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.

Return _the maximum profit you can achieve from this transaction_. If you cannot achieve any profit, return `0`.

**Example 1:**

**Input:** prices = \[7,1,5,3,6,4\]
**Output:** 5
**Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

**Example 2:**

**Input:** prices = \[7,6,4,3,1\]
**Output:** 0
**Explanation:** In this case, no transactions are done and the max profit = 0.

## My ANSWER

````cpp
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) {
        return 0;  // No profit can be made with less than 2 prices
    }

    int min = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < min) {
            min = prices[i];  // Update the minimum price
        } else {
            int profit = prices[i] - min;  // Calculate the potential profit
            if (profit > maxProfit) {
                maxProfit = profit;  // Update the maximum profit
            }
        }
    }

    return maxProfit;
}```
````

# Intuition

We can solve this problem using Three approach.

1. Solved using Array(Two Nested Loop). Brute Force Approach.
2. Solved using Dynamic Programming Approach (tabulation).
3. Solved using Dynamic Programming Approach(Space optimization).

# Approach

We can easily understand the All the approaches by seeing the code which is easy to understand with comments.

# Complexity

- Time complexity:

Time complexity is given in code comment.

- Space complexity:

Space complexity is given in code comment.

# Code

```cpp
/*

    Time Complexity : O(N^2), Where N is the size of the Array(prices). As we check for possible pair, and the
    total number of pairs are : N*(N–1)/2.

    Space complexity : O(1), Constant space.

    Using Array(Two Nested Loop). Brute Force Approach.

    Note : This will give TLE.

*/


/***************************************** Approach 1 Code *****************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(prices[j] - prices[i] > maxProfit){
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        return maxProfit;
    }
};






/*

    Time Complexity : O(N), As we iterate the array(prices) two times. Where N = size of the array.

    Space complexity : O(N), Array(maxPrices) space.

    Solved using Dynamic Programming Approach(tabulation).

*/


/***************************************** Approach 2 Code *****************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxPrices(n, 0);
        maxPrices[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            maxPrices[i] = max(maxPrices[i+1], prices[i]);
        }
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            maxProfit = max(maxProfit, maxPrices[i] - prices[i]);
        }
        return maxProfit;
    }
};






/*

    Time Complexity : O(N), As we iterate the array(prices) two times. Where N = size of the array.

    Space Complexity : O(1), Constant space.

    Solved using Dynamic Programming Approach(Space optimisation).

*/


/***************************************** Approach 3 Code *****************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyAtPrice = INT_MAX;
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            buyAtPrice = min(buyAtPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - buyAtPrice);
        }
        return maxProfit;
    }
};
```
