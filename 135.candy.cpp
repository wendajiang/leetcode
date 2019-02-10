/*
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (25.23%)
 * Total Accepted:    77.5K
 * Total Submissions: 306.8K
 * Testcase Example:  '[0]'
 *
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 *
 *
 * You are giving candies to these children subjected to the following
 * requirements:
 *
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 *
 *
 * What is the minimum candies you must give?
 *
 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len == 1) return 1;

        int sum = 0;
        vector<int> v(len, 1); //init every child have a Candy

        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i - 1])
                v[i] = v[i - 1] + 1;
        }

        for(int i = len - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1] && v[i] <= v[i + 1])
                v[i] = v[i + 1] + 1;
        }
        for(int i = 0; i < len; i++)
            sum += v[i];
        return sum;
    }
};
