/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams
 *
 * Medium (34.25%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 *
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 *
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * Note: All inputs will be in lower-case.
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};//最多10609个z
        vector<vector<string>> res;
        map<int,int> mp;
        for(string s : strs){
            int key = 1;
            for(auto e : s){
                key *= prime[e - 'a'];
            }
            if(mp.find(key) != mp.end()){
                res[mp[key]].push_back(s);
            }else{
                vector<string> solution;
                solution.push_back(s);
                res.push_back(solution);
                mp[key] = res.size() - 1;
            }
        }
        //为了匹配答案的顺序
        for(int i = 0; i < res.size(); i++){
            std::sort(res[i].begin(), res[i].end(), [](string a, string b){return a < b;});
        }
        std::sort(res.begin(), res.end(), [](vector<string> a, vector<string> b){return a.size() < b.size();});

        return res;
    }
};
