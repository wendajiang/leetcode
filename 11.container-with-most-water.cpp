/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water
 *
 * Medium (36.44%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;  //make (end - start) max
        int maxC = INT_MIN;
        while(start < end){
            int container = std::min(height[end], height[start]) * (end - start);
            maxC = std::max(maxC, container);
            if(height[start] <= height[end]){ //change the shorter board which only may make the container bigger ,when the bottom board is smaller
                start++;
            }else{
                end--;
            }
        }
        return maxC;
    }

};
