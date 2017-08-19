/*
 * [532] K-diff Pairs in an Array
 *
 * https://leetcode.com/problems/k-diff-pairs-in-an-array
 *
 * algorithms
 * Easy (28.18%)
 * Total Accepted:    21.1K
 * Total Submissions: 74.8K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 *
 * Given an array of integers and an integer k, you need to find the number of
 * unique k-diff pairs in the array. Here a k-diff pair is defined as an
 * integer pair (i, j), where i and j are both numbers in the array and their
 * absolute difference is k.
 *
 *
 *
 * Example 1:
 *
 * Input: [3, 1, 4, 1, 5], k = 2
 * Output: 2
 * Explanation: There are two 2-diff pairs in the array, (1, 3) and (3,
 * 5).Although we have two 1s in the input, we should only return the number of
 * unique pairs.
 *
 *
 *
 * Example 2:
 *
 * Input:[1, 2, 3, 4, 5], k = 1
 * Output: 4
 * Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3,
 * 4) and (4, 5).
 *
 *
 *
 * Example 3:
 *
 * Input: [1, 3, 1, 5, 4], k = 0
 * Output: 1
 * Explanation: There is one 0-diff pair in the array, (1, 1).
 *
 *
 *
 * Note:
 *
 * The pairs (i, j) and (j, i) count as the same pair.
 * The length of the array won't exceed 10,000.
 * All the integers in the given input belong to the range: [-1e7, 1e7].
 *
 *
 */
class Solution {
public:

    // //O(n^2) method
    // int findPairs(vector<int>& nums, int k) {
    //     int res = 0;
    //     set<pair<int, int>> tmp;
    //     for(int i = 0; i < nums.size(); i++){
    //         for(int j = i + 1; j < nums.size(); j++){
    //             if(abs(nums[i] - nums[j]) == k && tmp.find(make_pair(nums[i], nums[j])) == tmp.end()){
    //                 res++;
    //                 tmp.insert(make_pair(nums[i], nums[j]));
    //                 tmp.insert(make_pair(nums[j], nums[i]));
    //             }
    //         }
    //     }
    //     return res;
    // }

    // //O(nlogn) sort and slide window ,Two-pointer Approach
    // int findPairs(vector<int>& nums, int k) {
    //     int res = 0;
    //     std::sort(nums.begin(), nums.end());
    //     int i = 0, j = 1;
    //     while(j < nums.size()){
    //         if(j <= i || nums[j] - nums[i] < k){
    //             j++;
    //         }else if((i > 0 && nums[i] == nums[i - 1]) || nums[j] - nums[i] > k){
    //             i++;
    //         }else {
    //             i++;
    //             res++;
    //         }
    //     }
    //     return res;
    // }

    int findPairs(vector<int>& nums, int k){
        if(k < 0) return 0;
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] ++;
        }
        if(k != 0){
            for(auto it = mp.begin(); it != mp.end(); it++){
                if(mp.find(it->first + k) != mp.end())
                    res++;
            }
        }else{
            for(auto it = mp.begin(); it != mp.end(); it++){
                if(it->second > 1)
                    res++;
            }
        }
        return res;
    }
};
