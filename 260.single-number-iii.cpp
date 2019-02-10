/*
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (53.02%)
 * Total Accepted:    80.4K
 * Total Submissions: 151.3K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 *
 *
 * For example:
 *
 *
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 *
 * Note:
 *
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 *
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:

    /*
    我们知道如果一个数组中只有一个元素是出现一次，其他元素是出现两次的解题思路。只需要把所有的元素异或之后，那么异或的结果就是那个最终的单个的元素。
    这个思路很简单，就是把每个数理解为对应的二进制位，那么那些出现两次的元素，他们在1出现的所有位置，1都出现两次，异或完就还是0。
    而对于那个单出现一次得元素，它每个二进制位对应的数字出现一次。所以最终的异或结果就相当于把出现两次的元素全部去除。
    有了上面的基本的思路，我们可以将数组分成两个部分，每个部分里只有一个元素出现一次，其余元素都出现两次。
    那么使用这种方法就可以找出这两个元素了。不妨假设这两个元素是x，y,而且x!=y，那么最终所有的元素异或的结果就是res = x^y.
    很显然，res!= 0，如果res=0，那么x=y，与题意不符。既然res！=0，那么我们可以找出其二进制表示中的某一位是1，我们从低位往高位找，
    找到第一个二进制位是1的位置。对于原来的数组，我们可以根据这个位置是不是1就可以将数组分成两个部分。
    x，y在不同的两个子数组中。而且对于其他成对出现的元素，要么在x所在的那个数组，要么在y所在的那个数组。
    假设不是的话，那说明这一对数在这一位上一个是0一个是1，很显然不符它们是一对相等数的条件。


    */
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= ~(diff - 1);
        //diff &= -diff;

        vector<int> res = {0, 0};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & diff){
                res[0] ^= nums[i];
            }else{
                res[1] ^= nums[i];
            }
        }
        return res;
    }
};
