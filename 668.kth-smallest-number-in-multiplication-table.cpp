/*
 * [668] Kth Smallest Number in Multiplication Table
 *
 * https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
 *
 * algorithms
 * Hard (40.08%)
 * Total Accepted:    5.9K
 * Total Submissions: 14.8K
 * Testcase Example:  '3\n3\n5'
 *
 *
 * Nearly every one have used the Multiplication Table. But could you find out
 * the k-th smallest number quickly from the multiplication table?
 *
 *
 *
 * Given the height m and the length n of a m * n Multiplication Table, and a
 * positive integer k, you need to return the k-th smallest number in this
 * table.
 *
 *
 * Example 1:
 *
 * Input: m = 3, n = 3, k = 5
 * Output:
 * Explanation:
 * The Multiplication Table:
 * 1    2    3
 * 2    4    6
 * 3    6    9
 *
 * The 5-th smallest number is 3 (1, 2, 2, 3, 3).
 *
 *
 *
 *
 * Example 2:
 *
 * Input: m = 2, n = 3, k = 6
 * Output:
 * Explanation:
 * The Multiplication Table:
 * 1    2    3
 * 2    4    6
 *
 * The 6-th smallest number is 6 (1, 2, 2, 3, 4, 6).
 *
 *
 *
 *
 * Note:
 *
 * The m and n will be in the range [1, 30000].
 * The k will be in the range [1, m * n]
 *
 *
 */
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1;
        int r = m * n;
        for(int cnt = 0; l < r; cnt = 0){
            int mid = (l + r) / 2;
            for(int i = 0, j = n - 1; i < m; i++){
                while(j >= 0 && (i + 1) * (j + 1) > mid) j--;
                cnt += (j + 1);
            }
            if(cnt < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
