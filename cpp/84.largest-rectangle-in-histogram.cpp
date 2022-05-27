/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (27.51%)
 * Total Accepted:    115.1K
 * Total Submissions: 417.7K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 *
 *
 *
 *
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 *
 *
 *
 *
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 *
 *
 *
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 *
 */
class Solution {
public:

    // //TLE,要使用单调栈维护一个L, 和一个R的集合
    // int largestRectangleArea(vector<int>& heights) {
    //     int maxH = 0;
    //     for(int i = 0; i < heights.size(); i++){
    //         int h = heights[i];
    //         int L = i, R = i;
    //         while(L - 1 >= 0 && heights[L - 1] >= heights[i]) L--;
    //         while(R + 1 < heights.size() && heights[R + 1] >= heights[i]) R++;
    //         maxH = max(maxH, h * (R - L + 1));
    //     }
    //     return maxH;
    // }

    // int largestRectangleArea(vector<int>& heights){
    //     int maxH = 0;
    //     int len = heights.size();
    //     vector<int> L(len, 0), R(len, 0);
    //
    //     stack<int> st;
    //     for(int i = 0; i < len; i++){
    //         while(!st.empty() && heights[st.top()] > heights[i]){
    //             R[st.top()] = i - st.top() - 1;
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    //     while(!st.empty()){
    //         R[st.top()] = len - 1 - st.top();
    //         st.pop();
    //     }
    //     for(int i = len - 1; i >= 0; i--){
    //         while(!st.empty() && heights[st.top()] > heights[i]){
    //             L[st.top()] = st.top() - i - 1;
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    //     while(!st.empty()){
    //         L[st.top()] = st.top() - 0;
    //         st.pop();
    //     }
    //
    //     // for(int i = 0; i < len; i++){
    //     //     cout << i << " " << L[i] << " " << R[i] << endl;
    //     // }
    //
    //     for(int i = 0; i < len; i++){
    //         maxH = max(maxH, heights[i] * (L[i] + R[i] + 1));
    //     }
    //     return maxH;
    // }


    //上面是两趟分别求出最左和最右，下面的代码一趟直接求出 凹 字形的面积，维护一个单调增栈
    int largestRectangleArea(vector<int>& heights){
        int maxH = 0;
        heights.push_back(0);
        int len = heights.size();
        stack<int> st;

        for(int i = 0; i < len; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int h = heights[st.top()];
                st.pop();
                int lidx = st.empty() ? -1 : st.top();
                maxH = max(maxH, h * (i - lidx - 1));

            }
            st.push(i);
        }
        return maxH;
    }
};
