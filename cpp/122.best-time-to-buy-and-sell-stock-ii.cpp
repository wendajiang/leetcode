/*
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 *
 * Easy (46.69%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times). However, you may not engage in multiple transactions at the
 * same time (ie, you must sell the stock before you buy again).
 */
class Solution {
public:
    // 不用求差值数组，可以直接求
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        vector<int> diff;
        for(int i = 1; i < prices.size(); i++){
            diff.push_back(prices[i] - prices[i-1]);
        }
        int profit = 0;
        for(auto x : diff){
            if(x > 0)
                profit += x;
        }
        return profit;
    }
};
