/*
 * [812] Rotate String
 *
 * https://leetcode.com/problems/rotate-string/description/
 *
 * algorithms
 * Easy (54.46%)
 * Total Accepted:    11.6K
 * Total Submissions: 21.3K
 * Testcase Example:  '"abcde"\n"cdeab"'
 *
 * We are given two strings, A and B.
 *
 * A shift on A consists of taking string A and moving the leftmost character
 * to the rightmost position. For example, if A = 'abcde', then it will be
 * 'bcdea' after one shift on A. Return True if and only if A can become B
 * after some number of shifts on A.
 *
 *
 * Example 1:
 * Input: A = 'abcde', B = 'cdeab'
 * Output: true
 *
 * Example 2:
 * Input: A = 'abcde', B = 'abced'
 * Output: false
 *
 *
 * Note:
 *
 *
 * A and B will have length at most 100.
 *
 *
 */
class Solution {
public:
    // void rotate(string& A, int i){
    //     int l = 0, r = i;
    //     while(l < r){
    //         swap(A[l], A[r]);
    //         l++;
    //         r--;
    //     }
    //     l = i + 1; r = A.size() - 1;
    //     while(l < r){
    //         swap(A[l], A[r]);
    //         l++; r--;
    //     }
    //     l = 0; r = A.size() - 1;
    //     while(l < r){
    //         swap(A[l], A[r]);
    //         l++; r--;
    //     }
    // }
    // bool rotateString(string A, string B) {
    //     if(A.size() != B.size()) return 0;
    //     if(A.size() == 0 && B.size() == 0) return true;
    //     for(int i = 0; i < A.size() - 1; i++){
    //         string tmp = A;
    //         rotate(tmp, i);
    //         if(tmp == B) return true;
    //     }
    //     return false;
    // }

    bool rotateString(string A, string B){
        return (A.size() == B.size()) && (A + A).find(B) != string::npos;
    }
};
