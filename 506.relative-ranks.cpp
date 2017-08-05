/*
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks
 *
 * Easy (46.53%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[5,4,3,2,1]'
 *
 *
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 *
 * Example 1:
 *
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 *
 *
 *
 * Note:
 *
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 *
 *
 *
 */
class Solution {
public:
    // //我的写的第一反应，看了discuss后，map实现方式可以直接有序，还有优先队列也可以实现
    // vector<string> findRelativeRanks(vector<int>& nums) {
    //     vector<int> tmpnums = nums;
    //     std::sort(tmpnums.begin(), tmpnums.end(), [](int a, int b){return a > b;});
    //     unordered_map<int, int> mp;
    //     for(int i = 0; i < tmpnums.size(); i++){
    //         mp[tmpnums[i]] = i;
    //     }
    //     vector<string> res;
    //     for(auto & e : nums){
    //         if(mp[e] == 1 - 1){
    //             res.push_back("Gold Medal");
    //         }else if(mp[e] == 2 - 1){
    //             res.push_back("Silver Medal");
    //         }else if(mp[e] == 3 - 1){
    //             res.push_back("Bronze Medal");
    //         }else {
    //             res.push_back(to_string(mp[e] + 1));
    //         }
    //     }
    //     return res;
    // }

    vector<string> findRelativeRanks(vector<int>& nums){
        // map<int, int> mp;
        // for(int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
        // vector<string> res(nums.size(), "");
        // int cnt = 1;
        // for(auto it = mp.rbegin(); it != mp.rend(); it++, cnt++){
        //     if(cnt == 1) res[it->second] = "Gold Medal";
        //     else if(cnt == 2) res[it->second] = "Silver Medal";
        //     else if(cnt == 3) res[it->second] = "Bronze Medal";
        //     else res[it->second] = to_string(cnt);
        // }
        // return res;

        priority_queue<pair<int,int> > pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        vector<string> res(nums.size(),"");
        int count = 1;
        for(int i=0; i<nums.size();i++)
        {
            if(count==1) {res[pq.top().second] = "Gold Medal"; count++;}
            else if(count==2) {res[pq.top().second] = "Silver Medal"; count++;}
            else if(count==3) {res[pq.top().second] = "Bronze Medal"; count++;}
            else {res[pq.top().second] = to_string(count); count++;}
            pq.pop();
        }
        return res;
    }
};
