/*
 * [826] Soup Servings
 *
 * https://leetcode.com/problems/soup-servings/description/
 *
 * algorithms
 * Medium (32.14%)
 * Total Accepted:    2.1K
 * Total Submissions: 6.2K
 * Testcase Example:  '50'
 *
 * There are two types of soup: type A and type B. Initially we have N ml of
 * each type of soup. There are four kinds of operations:
 *
 *
 * Serve 100 ml of soup A and 0 ml of soup B
 * Serve 75 ml of soup A and 25 ml of soup B
 * Serve 50 ml of soup A and 50 ml of soup B
 * Serve 25 ml of soup A and 75 ml of soup B
 *
 *
 * When we serve some soup, we give it to someone and we no longer have it.
 * Each turn, we will choose from the four operations with equal probability
 * 0.25. If the remaining volume of soup is not enough to complete the
 * operation, we will serve as much as we can.  We stop once we no longer have
 * some quantity of both types of soup.
 *
 * Note that we do not have the operation where all 100 ml's of soup B are used
 * first.  
 *
 * Return the probability that soup A will be empty first, plus half the
 * probability that A and B become empty at the same time.
 *
 *
 *
 *
 * Example:
 * Input: N = 50
 * Output: 0.625
 * Explanation:
 * If we choose the first two operations, A will become empty first. For the
 * third operation, A and B will become empty at the same time. For the fourth
 * operation, B will become empty first. So the total probability of A becoming
 * empty first plus half the probability that A and B become empty at the same
 * time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.
 *
 *
 *
 * Notes:
 *
 *
 * 0 <= N <= 10^9. 
 * Answers within 10^-6 of the true value will be accepted as correct.
 *
 */
class Solution {
public:
    //记忆化搜索，简化处理，离散点
    double dp[200][200];
    double soupServings(int N) {
        memset(dp, 0, sizeof(dp));
        return N >= 4800 ?  1.0 : dfs((N + 24) / 25, (N + 24) / 25);
    }
    double dfs(int a, int b) {
        if(a <= 0 && b <= 0) return 0.5;
        else if(a <= 0 && b > 0) return 1.0;
        else if(a > 0 && b <= 0) return 0.0;

        if(dp[a][b] > 0) return dp[a][b];
        dp[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) + dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
        return dp[a][b];
    }

//     //记忆化搜索
//     double soupServings(int N) {
//         if(N >= 50000)
//             return 1.0;
//         else
//             return dfs(N, N);
//     }
//     double dfs(int A, int B){
//         if(A == 0 && B != 0){
//             return 1.0;
//         }else if(A == 0 && B == 0){
//             return 0.5;
//         }else if(A != 0 && B == 0){
//             return 0.0;
//         }
//
//         if(store[A][B] != 0) return store[A][B];
//
//         double prob = 0;
//         prob += 0.25 * dfs(A - min(A, 100), B);
//         prob += 0.25 * dfs(A - min(A, 75), B - min(B, 25));
//         prob += 0.25 * dfs(A - min(A, 50), B - min(B, 50));
//         prob += 0.25 * dfs(A - min(A, 25), B - min(B, 75));
//
//         store[A][B] = prob;
//         return prob;
//     }
//
// private:
//     unordered_map<int, unordered_map<int, double>> store;
};
