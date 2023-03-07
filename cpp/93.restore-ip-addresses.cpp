//  Category: algorithms
//  Level: Medium
//  Percent: 43.70315%

//  A valid IP address consists of exactly four integers separated by single
//  dots. Each integer is between 0 and 255 (inclusive) and cannot have leading
//  zeros.
//
//
//  	For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
//  "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
//
//
//  Given a string s containing only digits, return all possible valid IP
//  addresses that can be formed by inserting dots into s. You are not allowed
//  to reorder or remove any digits in s. You may return the valid IP addresses
//  in any order.
//
//   
//  Example 1:
//
//  Input: s = "25525511135"
//  Output: ["255.255.11.135","255.255.111.35"]
//
//
//  Example 2:
//
//  Input: s = "0000"
//  Output: ["0.0.0.0"]
//
//
//  Example 3:
//
//  Input: s = "101023"
//  Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
//
//
//   
//  Constraints:
//
//
//  	1 <= s.length <= 20
//  	s consists of digits only.
//

#include <string>
#include <vector>
using namespace std;
//  @lc code=start
class Solution {
   public:
    // // solution one
    // vector<string> restoreIpAddresses(string s) {
    //     std::vector<std::string> res;
    //     for (int i = 1; i <= 3; i++) {
    //         for (int j = 1; j <= 3; j++) {
    //             for (int l = 1; l <= 3; l++) {
    //                 for (int k = 1; k <= 3; k++) {
    //                     if (i + j + l + k == s.size()) {
    //                         int a = std::stoi(s.substr(0, i));
    //                         int b = std::stoi(s.substr(i, j));
    //                         int c = std::stoi(s.substr(i + j, l));
    //                         int d = std::stoi(s.substr(i + j + l, k));
    //                         if (a <= 255 && b <= 255 && c <= 255 && d <= 255)
    //                         {
    //                             if (auto ans =
    //                                     to_string(a) + "." + to_string(b) +
    //                                     "." + to_string(c) + "." +
    //                                     to_string(d);
    //                                 ans.size() == s.size() + 3) {
    //                                 res.emplace_back(ans);
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    // }

    // solution two, recursive
    // https://blog.csdn.net/youngyangyang04/article/details/110007118
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        partition_ip(s, 0, 0, "", result);
        return result;
    }

    void partition_ip(string s, int start, int part_num, string res_ip,
                      vector<string> &res) {
        // max: 3bits per partition, if exceed return
        if (s.size() - start > (4 - part_num) * 3) return;
        // min: 1bit per partition, if not return
        if (s.size() - start < (4 - part_num)) return;
        if (start == s.size() && part_num == 4) {
            res_ip.resize(res_ip.size() - 1);
            res.push_back(res_ip);
            return;
        }
        int num = 0;
        for (int i = start; i < start + 3; i++) {
            num = num * 10 + (s[i] - '0');
            if (num <= 255) {
                res_ip += s[i];
                partition_ip(s, i + 1, part_num + 1, res_ip + '.', res);
            }
            if (num == 0) break;
        }
    }
};
//  @lc code=end
