/*
 * [800] Letter Case Permutation
 *
 * https://leetcode.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (52.37%)
 * Total Accepted:    9.8K
 * Total Submissions: 18.8K
 * Testcase Example:  '"a1b2"'
 *
 * Given a string S, we can transform every letter individually to be lowercase
 * or uppercase to create another string.  Return a list of all possible
 * strings we could create.
 *
 *
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 *
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 *
 * Input: S = "12345"
 * Output: ["12345"]
 *
 *
 * Note:
 *
 *
 * S will be a string with length at most 12.
 * S will consist only of letters or digits.
 *
 */
class Solution {
public:
    bool islower(char c){
        if(c >= 'a' && c <= 'z'){
            return true;
        }else{
            return false;
        }
    }
    void getS(int i, string S, int end, vector<string>& res){
        if(i == end){
            res.push_back(S);
            return;
        }
        if(isalpha(S[i])){
            if(islower(S[i])){
                getS(i + 1, S, end, res);
                S[i] -= 32;
                getS(i + 1, S, end, res);
            }else{
                S[i] += 32;
                getS(i + 1, S, end, res);
                S[i] -= 32;
                getS(i + 1, S, end, res);

            }
        }else{
            getS(i + 1, S, end, res);
        }
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        if(S.size() == 0) {
            res.push_back(S);
            return res;
        }
        getS(0, S, S.size(), res);
        return res;
    }
};
