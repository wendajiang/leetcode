/*
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses
 *
 * Medium (26.96%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"0000"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 *
 *
 * For example:
 * Given "25525511135",
 *
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 *
 */

/*
排列组合问题
可以通过　　递归　　遍历所有可能的解
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> result;
        string ip;
        partitionIP(s, 0, 0, ip, result);
        return result;
    }

    void partitionIP(string s, int startIndex, int partNum, string resultIP, vector<string> &col){
        //max: 3bits per partition
        if(s.size() - startIndex > (4 - partNum) * 3) return;
        //min: 1bit per partition
        if(s.size() - startIndex < (4 - partNum)) return;
        if(startIndex == s.size() && partNum == 4){
            resultIP.resize(resultIP.size() - 1);
            col.push_back(resultIP);
            return;
        }
        int num = 0;
        for(int i = startIndex; i < startIndex + 3; i++){
            num = num * 10 + (s[i] - '0');
            if(num <= 255){
                resultIP += s[i];
                partitionIP(s, i+1, partNum + 1, resultIP + '.', col);
            }
            if(num == 0)
                break;
        }
    }
};
