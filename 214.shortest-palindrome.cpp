/*
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (25.11%)
 * Total Accepted:    52.4K
 * Total Submissions: 208.4K
 * Testcase Example:  '"aacecaaa"'
 *
 *
 * Given a string S, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 *
 *
 * For example:
 * Given "aacecaaa", return "aaacecaaa".
 * Given "abcd", return "dcbabcd".
 *
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Thanks to @Freezen for additional test cases.
 */
class Solution {
public:
    // //TLE最后一条caseO(n)的时间复杂度超时 具体来说时间为2n
    // int getManacher(string& s){
    //     int len = s.size();
    //     string str = "$#";
    //     for(int i = 0 ; i < len; i++){
    //         str = str + s[i] + "#";
    //     }
    //     int len2 = str.size();
    //     vector<int> p(len2, 0);
    //     int id = 0, mx = 0;
    //     for(int i = 0; i < len2; i++){
    //         if(mx > i) p[i] = min(p[2 * id - i], mx - i);
    //         else p[i] = 1;
    //         for(; str[i - p[i]] == str[i + p[i]]; p[i]++);
    //         if(i + p[i] > mx){
    //             mx = i + p[i];
    //             id = i;
    //         }
    //     }
    //     int maxL = 1;
    //     for(int i = 0; i < len2; i++){
    //         if(i - p[i] == 0){
    //             maxL = max(maxL, p[i] - 1);
    //         }
    //     }
    //     return maxL;
    // }
    //
    // string shortestPalindrome(string s) {
    //     if(s.size() == 0){
    //         return "";
    //     }
    //     if(isPalin(s)) return s;
    //     int prefix = getManacher(s);
    //     if(prefix == s.size()) return s;
    //     string add = s.substr(prefix);
    //
    //     reverse(add.begin(), add.end());
    //     return add + s;
    // }
    //
    // bool isPalin(string& s){
    //     int l = 0, r = s.size();
    //     while(l < r){
    //         if(s[l] != s[r]) return false;
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }

    //上面是用manacher算法求最大子串回文长度，看题解为使用KMP思想求出最大前缀
    string shortestPalindrome(string s){
        string str = s;
        reverse(str.begin(), str.end());
        str = s + "#" + str; //加一个冗余字符，因为aaaa这种不加，最长前缀会变大
        int len1 = s.size(), len2 = str.size();
        vector<int> vec(len2, 0); //next数组
        int i = 1;
        int len = 0;
        while(i < len2){
            if(str[len] == str[i]){
                len++;
                vec[i] = len;
                i++;
            }else{
                if(len > 0)len = vec[len - 1];
                else {
                    vec[i] = len;
                    i++;
                }
            }
        }
        return str.substr(len1 + 1, len1 - vec[len2 - 1]) + s;

    }


};
