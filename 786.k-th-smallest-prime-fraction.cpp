/*
 * [802] K-th Smallest Prime Fraction
 *
 * https://leetcode.com/problems/k-th-smallest-prime-fraction/description/
 *
 * algorithms
 * Hard (28.52%)
 * Total Accepted:    2K
 * Total Submissions: 6.5K
 * Testcase Example:  '[1,2,3,5]\n3'
 *
 * A sorted list A contains 1, plus some number of primes.  Then, for every p <
 * q in the list, we consider the fraction p/q.
 *
 * What is the K-th smallest fraction considered?  Return your answer as an
 * array of ints, where answer[0] = p and answer[1] = q.
 *
 *
 * Examples:
 * Input: A = [1, 2, 3, 5], K = 3
 * Output: [2, 5]
 * Explanation:
 * The fractions to be considered in sorted order are:
 * 1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
 * The third fraction is 2/5.
 *
 * Input: A = [1, 7], K = 1
 * Output: [1, 7]
 *
 *
 * Note:
 *
 *
 * A will have length between 2 and 2000.
 * Each A[i] will be between 1 and 30000.
 * K will be between 1 and A.length * (A.length - 1) / 2.
 *
 */
class Solution {
public:
    // // 慢多了
    // vector<int> kthSmallestPrimeFraction(vector<int>& A, int K){
    //     int n = A.size();
    //     auto cmp = [&A, &n](pair<int, int>& a, pair<int, int>& b){
    //         return A[a.first] * A[n - 1 - b.second] > A[n - 1 - a.second] * A[b.first];
    //     };
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    //     for(int i = 0; i < n; i++){
    //         pq.push(make_pair(i, 0));
    //     }
    //     while(--K){
    //         pair<int, int> p = pq.top(); pq.pop();
    //         if(++p.second < n){
    //             pq.push(p);
    //         }
    //     }
    //     return {A[pq.top().first], A[n - 1 - pq.top().second]};
    // }

    // vector<int> kthSmallestPrimeFraction(vector<int>& A, int k){
        // double l = 0, r = 1;
        // int p = 0, q = 1;
        // for(int n = A.size(), cnt = 0; true; cnt = 0, p = 0){
        //     double m = (l + r) / 2;
        //     for(int i = 0, j = n - 1; i < n; i++){
        //         while(j >= 0 && A[i] > m * A[n - 1 - j]) j--;
        //         cnt += (j + 1);
        //         if(j >= 0 && p * A[n - 1 - j] < q * A[i]){
        //             p = A[i];
        //             q = A[n - 1 - j];
        //         }
        //     }
        //     if(cnt < k){
        //         l = m;
        //     }else if(cnt > k){
        //         r = m;
        //     }else{
        //         return {p, q};
        //     }
        // }
    // }
};
