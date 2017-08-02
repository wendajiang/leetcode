/*
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers
 *
 * Easy (45.22%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 *
 * Example 1:
 *
 * Input: [1,2,3]
 * Output: 6
 *
 *
 *
 * Example 2:
 *
 * Input: [1,2,3,4]
 * Output: 24
 *
 *
 *
 * Note:
 *
 * The length of the given array will be in range [3,104] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 *
 *
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // if(nums.size() < 3) return 0;
        // std::sort(nums.begin(), nums.end());
        // int len = nums.size();
        // return std::max(nums[len - 1] * nums[len - 2] * nums[len - 3],
        //                 nums[len - 1] * nums[0] * nums[1]);
        int max3 = INT_MIN;
        int max2 = INT_MIN;
        int max1 = INT_MIN;
        int min2 = INT_MAX;
        int min1 = INT_MAX;
        for(auto & e : nums){
            if(e > max1){
                max3 = max2;
                max2 = max1;
                max1 = e;
            }else if(e > max2){
                max3 = max2;
                max2 = e;
            }else if(e > max3){
                max3 = e;
            }

            if(e < min1){
                min2 = min1;
                min1 = e;
            }else if(e < min2){
                min2 = e;
            }
        }
        return std::max(max3 * max2 * max1, max1 * min1 *min2);
    }
};
