/*
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title
 *
 * Easy (25.74%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 *
 * For example:
 *
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB
 *
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    string convertToTitle(int n) {
        if(n == 0) return "";
        string res;
        map<int,char> dict;
        dict[0] = 'Z';  //key point
        for(int i = 1; i <= 26; i++){
            dict[i] = 'A' + i - 1;
        }
        long tmp = n;
        while(tmp){
            int x = tmp % 26;
            tmp = (tmp - 1) / 26; //key point 至于为什么减1，举例可以说明，52的例子
            res.insert(res.begin(), dict[x]);
        }
        return res;
    }
};
