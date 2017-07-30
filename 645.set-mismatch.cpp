/*
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch
 *
 * Easy (40.82%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,2,2,4]'
 *
 *
 * The set S originally contains numbers from 1 to n. But unfortunately, due to
 * the data error, one of the numbers in the set got duplicated to another
 * number in the set, which results in repetition of one number and loss of
 * another number.
 *
 *
 *
 * Given an array nums representing the data status of this set after the
 * error. Your task is to firstly find the number occurs twice and then find
 * the number that is missing. Return them in the form of an array.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 *
 *
 *
 * Note:
 *
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 *
 *
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        int duplicate = 0, miss = 0;
        vector<bool> appear(nums.size() + 1, false);
        for(auto e : nums){
            if(!appear[e]){
                appear[e] = true;
            }else if(appear[e]){
                duplicate = e;
                break;
            }
        }
        res.push_back(duplicate);
        for(int i = 0; i < nums.size(); i++){
            duplicate ^= nums[i];
            duplicate ^= (i + 1);
        }
        miss = duplicate;
        res.push_back(miss);
        return res;
    }
};
