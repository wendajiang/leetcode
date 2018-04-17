/*
 * [830] Largest Triangle Area
 *
 * https://leetcode.com/problems/largest-triangle-area/description/
 *
 * algorithms
 * Easy (52.43%)
 * Total Accepted:    2.8K
 * Total Submissions: 5.4K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
 *
 * You have a list of points in the plane. Return the area of the largest
 * triangle that can be formed by any 3 of the points.
 *
 *
 * Example:
 * Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * Output: 2
 * Explanation:
 * The five points are show in the figure below. The red triangle is the
 * largest.
 *
 *
 *
 *
 * Notes:
 *
 *
 * 3 <= points.length <= 50.
 * No points will be duplicated.
 * -50 <= points[i][j] <= 50.
 * Answers within 10^-6 of the true value will be accepted as correct.
 *
 *
 *
 */
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0.0, area = 0.0;
        for (auto &p1 : points) {
            for (auto &p2 : points) {
                for (auto &p3 : points) {
                    area = abs(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] -
                               p2[0] * p1[1] - p3[0] * p2[1] - p1[0] * p3[1]) / 2.0;
                    max_area = max(max_area, area);  
                }
            }
        }
        return max_area;
    }
};
