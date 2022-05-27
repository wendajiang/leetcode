/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings
 *
 * algorithms
 * Medium (27.07%)
 * Total Accepted:    108.3K
 * Total Submissions: 400K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2.
 *
 * Note:
 *
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 *
 *
 */
class Solution {
public:
    // string multiply(string num1, string num2) {
    //     int m = num1.size();
    //     int n = num2.size();
    //     vector<int> res(m + n, 0);
    //     for(int i = m - 1; i >= 0; i--){
    //         for(int j = n - 1; j >= 0; j--){
    //             int mul = (num1[i] - '0') * (num2[j] - '0');
    //             int p1 = i + j, p2 = i + j + 1;
    //             int sum = res[p2] + mul;
    //
    //             res[p1] += sum / 10;
    //             res[p2] = sum % 10;
    //
    //         }
    //     }
    //     string ans;
    //     int index = 0;
    //     while(res[index] == 0){
    //         index++;
    //     }
    //     for(; index < m + n; index++){
    //         ans.append(to_string(res[index]));
    //     }
    //     return ans.empty() ? "0" : ans;
    // }

    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');

        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }

        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }

};
