/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary
 *
 * Easy (32.07%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"0"\n"0"'
 *
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 *
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 */
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0 && b.size() == 0)
            return "";
        if(a.size() && !b.size())
            return b;
        if(b.size() && !a.size())
            return a;

        string res;
        int c = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i >= 0 || j >= 0){
            int anum = (i >= 0) ? (a[i] - '0') : 0;
            int bnum = (j >= 0) ? (b[j] - '0') : 0;
            int sum = (anum + bnum + c) % 2;
            c = (anum + bnum + c) / 2;
            res.insert(0, to_string(sum));
            i--;
            j--;
        }
        return c != 0 ? res.insert(0, to_string(c)) : res;

    }
};
