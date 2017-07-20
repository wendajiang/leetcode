/*
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
 *
 * Hard (29.05%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 */
class Solution {
public:
    //final = max(maxprofit(0,i) + maxprofit(i+1,n))
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        vector<int> maxProfitLeft(prices.size(), 0);
        vector<int> maxProfitRight(prices.size(), 0);
        int minV = INT_MAX, maxP = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            if(minV > prices[i]) minV = prices[i];
            int tmp = prices[i] - minV;
            if(tmp > maxP)
                maxP = tmp;
            maxProfitLeft[i] = maxP;
        }
        int maxV = INT_MIN;
        maxP = INT_MIN;
        for(int i = prices.size() - 1; i >= 0; i--){
            if(maxV < prices[i]) maxV = prices[i];
            int tmp = maxV - prices[i];
            if(tmp > maxP)
                maxP = tmp;
            maxProfitRight[i] = maxP;
        }
        
        int finalMaxP = INT_MIN;
        for(int i = 0; i < prices.size() - 1; i++){
            finalMaxP = std::max(finalMaxP, maxProfitLeft[i] + maxProfitRight[i + 1]);
        }
        if(finalMaxP < maxProfitRight[0])
            finalMaxP = maxProfitRight[0];
        return finalMaxP;
    }
};
