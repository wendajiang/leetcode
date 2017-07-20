/*
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 *
 * Easy (40.82%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one
 * and sell one share of the stock), design an algorithm to find the maximum
 * profit.
 *
 * Example 1:
 *
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5
 *
 * max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger
 * than buying price)
 *
 *
 *
 * Example 2:
 *
 * Input: [7, 6, 4, 3, 1]
 * Output: 0
 *
 * In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 */
class Solution {
public:
    // 不用DP，可以直接做
    int maxProfit(vector<int>& prices){
        if(prices.size() <= 1) return 0;
        int minV = INT_MAX;
        int maxP = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            minV = std::min(minV, prices[i]);
            maxP = std::max(maxP, prices[i] - minV);
        }
        return maxP;
    }

    // int maxProfit(vector<int>& prices) {
    //     vector<int> diff;
    //     for(int i = 1; i < prices.size(); i++){
    //         diff.push_back(prices[i] - prices[i-1]);
    //         // cout << diff.back() << " ";
    //     }
    //     //compute prefix of diff
    //     for(int i = 1; i < diff.size(); i++){
    //         diff[i] += diff[i - 1];
    //         // cout << diff[i] << " ";
    //     }
    //     int minPre = 0;
    //     int profit = INT_MIN;
    //     for(int i = 0; i < diff.size(); i++){
    //         profit = std::max(profit, diff[i] - minPre);
    //         minPre = std::min(minPre, diff[i]);
    //     }
    //     if(profit < 0)
    //         return 0;
    //     return profit;
    // }


};
