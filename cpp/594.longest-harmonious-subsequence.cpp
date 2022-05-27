/*
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence
 *
 * Easy (40.14%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array is an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 *
 * Now, given an integer array, you need to find the length of its longest
 * harmonious subsequence among all its possible subsequences.
 *
 * Example 1:
 *
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 *
 *
 *
 * Note:
 * The length of the input array will not exceed 20,000.
 *
 *
 *
 */
class Solution {
public:

    // // 时间为O(n),空间也为O(n)
    // int findLHS(vector<int>& nums) {
    //     map<int,int> freqs;
    //     for(auto x : nums){
    //         freqs[x]++;
    //     }
    //     int longest = 0;
    //     int lastNum = 0;
    //     int lastFreq = 0;
    //     for(pair<int,int> p : freqs){
    //         int freq2 = 0;
    //         if (lastFreq && p.first == lastNum + 1) {
    //             freq2 = p.second + lastFreq;
    //         }
    //         longest = max(longest, freq2);
    //         lastNum = p.first;
    //         lastFreq = p.second;
    //     }
    //     return longest;
    // }
    int findLHS(vector<int>& nums){
        if(nums.size() == 0) return 0;
        std::sort(nums.begin(), nums.end());
        int longest = 0;
        int start = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[start] > 1){
                start++;
                i--;
            }else if(nums[i] - nums[start] == 1){
                longest = std::max(longest, i - start + 1);
            }
        }
        return longest;
    }

};
