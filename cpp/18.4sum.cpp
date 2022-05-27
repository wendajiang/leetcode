/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum
 *
 * Medium (26.51%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array S of n integers, are there elements a, b, c, and d in S such
 * that a + b + c + d = target? Find all unique quadruplets in the array which
 * gives the sum of target.
 *
 * Note: The solution set must not contain duplicate quadruplets.
 *
 *
 *
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 */

/*
解题思路：
很简单，就是把分别把两个数进行求和，然后使用这个新的scom进行两个数的求target，但是
要构造一个数据结构来保存两个数求和的metadata，以便重新构造解
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > vvi;
        int n = nums.size();
        if(n < 4) return  vvi;

        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>> > mp;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mp[nums[i]+nums[j]].push_back(make_pair(i,j));
            }
        }//对应的sum，记录两个index

        for(int i = 0; i < n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int res = target - nums[i] - nums[j];
                if(mp.count(res)){
                    for(auto it = mp[res].begin(); it != mp[res].end(); it++){
                        int k = (*it).first, l = (*it).second;
                        if(k > j){ // k>j make sure that the second pair has bigger values than the first pair.
                            if(!vvi.empty() && nums[i]==vvi.back()[0] && nums[j]==vvi.back()[1]
                            && nums[k]==vvi.back()[2] && nums[l] == vvi.back()[3]){
                                continue; //if the obtained 4 elements are the same as previous one continue to next
                            }
                            vector<int> vi={nums[i], nums[j], nums[k], nums[l]};
                            vvi.push_back(vi);
                        } // if k>j

                    }//for it
                }//if
            }// forj
        }//for i
        return vvi;
    }
};
