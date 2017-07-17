/*
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
 *
 * Easy (47.12%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[2,3,4]\n6'
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they
 * add up to the target, where index1 must be less than index2. Please note
 * that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 *
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int end = numbers.size() - 1;
        int begin = 0;
        int sum = 0;
        while(begin < end){
            sum = numbers[begin] + numbers[end];
            if(sum == target){
                res.push_back(begin + 1);
                res.push_back(end + 1);
                return res;
            }else if(sum < target){
                begin ++;
            }else{
                end --;
            }
        }
        return res;
    }
};
