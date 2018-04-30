/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (38.27%)
 * Total Accepted:    140.2K
 * Total Submissions: 365.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 */
class Solution {
public:
    // int longestConsecutive(vector<int>& nums) {
    //     if(nums.size() == 0) return 0;
    //     set<int> bt;
    //     for(int e : nums){
    //         bt.insert(e);
    //     }
    //     auto cur = bt.begin();
    //     set<int>::iterator pre;
    //     int step = 1;
    //     int res = INT_MIN;
    //     while(cur != bt.end()){
    //             pre = cur;
    //             cur++;
    //             if(cur == bt.end()){
    //                 res = max(res, step);
    //                 break;
    //             }
    //             if(*(cur) == *(pre) + 1){
    //                 step ++;
    //                 res = max(step, res);
    //             }else{
    //                 step = 1;
    //                 res = max(step, res);
    //             }
    //     }
    //     return res;
    // }

    // int longestConsecutive(vector<int>& nums){
    //     int res = 0;
    //     unordered_map<int, int> ump;
    //     for(auto e : nums){
    //         if(ump.find(e) == ump.end()){
    //             int left = (ump.find(e - 1) != ump.end()) ? ump[e - 1] : 0;
    //             int right = (ump.find(e + 1) != ump.end()) ? ump[e + 1] : 0;
    //             // sum: length of the sequence n is in
    //             int sum = left + right + 1;
    //             ump[e] = sum;
    //
    //             // extend the length to the boundary(s)
    //             // of the sequence
    //             // will do nothing if n has no neighbors
    //             res = max(res, sum);
    //             ump[e - left] = sum;
    //             ump[e + right] = sum;
    //         }else{
    //             //duplicates
    //             continue;
    //         }
    //     }
    //     return res;
    // }

    int longestConsecutive(vector<int>& nums){
        sort(nums.begin(), nums.end());

        int max_sum = 0;
        int sum = 0;

        if (nums.size() <= 1)
            return nums.size();

        sum = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if ((nums[i]-nums[i-1]) == 1 || (nums[i]-nums[i-1]) == 0)
            {
                if ((nums[i]-nums[i-1]) == 1)
                    sum++;
            }
            else
            {
                max_sum = max(max_sum, sum);
                sum = 1;
            }
           // cout << sum << endl;
        }

        max_sum = max(max_sum, sum);
        return max_sum;
    }
};
