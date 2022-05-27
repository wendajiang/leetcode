/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern
 *
 * Easy (32.96%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * ⁠Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 *
 * Examples:
 *
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 *
 *
 *
 *
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 *
 *
 * Credits:Special thanks to @minglotus6 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mp;
        stringstream ss(str);
        vector<string> cut;
        string tmp;
        while(ss >> tmp){
            cut.push_back(tmp);
        }
        if(pattern.size() != cut.size())
            return false;
        for(int i = 0; i < pattern.size(); i++){
            if(mp.find(pattern[i]) == mp.end()){
                tmp = cut[i];
                if(std::find_if(mp.begin(), mp.end(), [tmp](pair<char, string> a){ return a.second == tmp;}) != mp.end())
                    return false;
                mp[pattern[i]] = cut[i];
            }else{
                if(mp[pattern[i]] != cut[i])
                    return false;
            }
        }
        return true;
    }
};
