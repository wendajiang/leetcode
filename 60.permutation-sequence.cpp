/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (29.52%)
 * Total Accepted:    101.6K
 * Total Submissions: 344.1K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 *
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note:
 *
 *
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 3
 * Output: "213"
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4, k = 9
 * Output: "2314"
 *
 *
 */
class Solution {
public:

    string getPermutation(int n, int k) {
        string st;
        for(int i = 1; i <= n; i++){
            st.append(to_string(i));
        }
        vector<int> sb(n, 1);
        for(int i = 2; i < sb.size(); i++){
            sb[i] = i * sb[i - 1];
        }
        string res = "";
        k = k - 1;
        for(int i = n - 1; i >= 0; i--){
            int ind = k / sb[i];
            k = k % sb[i];
            res += st[ind];
            st.erase(ind, 1);
        }
        return res;
    }
};
