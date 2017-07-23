/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number
 *
 * Easy (46.87%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"A"'
 *
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int len = s.size();
        for(int i = len - 1; i >= 0; i--){
            res += ((s[i] - 'A' + 1) * pow(26, (len - 1 - i)));
        }
        return res;
    }

    int pow(int x, int n){
        if(n == 0) return 1;
        if((n & 1) == 0)
            return pow(x, n / 2) * pow(x, n/2);
        else
            return pow(x, n / 2) * pow(x, n/2) * x;
    }
};
