/*
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number
 *
 * Easy (27.84%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 *
 * Example 1:
 *
 * Input: [3, 2, 1]
 *
 * Output: 1
 *
 * Explanation: The third maximum is 1.
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 2]
 *
 * Output: 2
 *
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 *
 *
 *
 * Example 3:
 *
 * Input: [2, 2, 3, 1]
 *
 * Output: 1
 *
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 *
 *
 */
class Solution {
public:

    int thirdMax(vector<int>& nums){
        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;
        for(auto e : nums){
            if(e == max1 || e == max2 || e == max3) continue;//忽略相同元素
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
        }
        // return max3 == INT_MIN ? max1 : max3;//如果max3就是INT_MIN就挂了
        return max3 == LONG_MIN ? max1 : max3;

    }
    // //sort
    // int thirdMax(vector<int>& nums) {
    //     if(nums.size() == 0) return 0;
    //     std::sort(nums.begin(), nums.end(), [](int a, int b){ return a > b; });
    //     // for(auto e : nums)
    //     //     cout << e << " ";
    //     // if(nums.size() < 3) return nums[0];
    //     int count = 2;
    //     int index = 0;
    //     while(count && index < nums.size()){
    //         count--;
    //         while(index < nums.size() - 1 && nums[index] == nums[index + 1])
    //             index++;
    //         index++;
    //     }
    //     if(index == nums.size()) return nums[0];
    //     else return nums[index];
    // }


};
