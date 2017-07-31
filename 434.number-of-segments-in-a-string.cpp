/*
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string
 *
 * Easy (36.78%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 *
 * Please note that the string does not contain any non-printable characters.
 *
 * Example:
 *
 * Input: "Hello, my name is John"
 * Output: 5
 *
 *
 */
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string tmp;
        int count = 0;
        while(ss >> tmp){
            count++;
        }
        return count;
    }
};
