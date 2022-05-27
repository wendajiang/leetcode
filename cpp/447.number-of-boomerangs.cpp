/*
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs
 *
 * Easy (44.88%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 *
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 *
 * Example:
 *
 * Input:
 * [[0,0],[1,0],[2,0]]
 *
 * Output:
 * 2
 *
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 *
 *
 */
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<long, int> group(points.size());
            // iterate over all points other than points[i]
            for(int j = 0; j < points.size(); j++){
                if( i == j ) continue;
                int distance = getDistanceSquare(points[i], points[j]);
                // group[distance]++;
                res += 2 * group[distance]++;//不用下面的一个循环，在此做加法优化速度
                                             //实际上就是n(n-1)
            }
            // for(auto &g : group){
            //     if(g.second > 1){
            //         /*
            //         * for all the groups of points,
            //         * number of ways to select 2 from n -> C(2,n) = n(n-1) / 2
            //         * but every the behind two points can be any order
            //         * C(2,n) * A(2,2) = n(n - 1)
            //         */
            //         res += (g.second - 1) * g.second;
            //     }
            // }
        }
        return res;
    }

    int getDistanceSquare(pair<int, int> a, pair<int, int> b){
        int x = a.first - b.first;
        int y = a.second - b.second;
        return x*x + y*y;
    }
};
