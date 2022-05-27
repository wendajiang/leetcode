/*
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (29.48%)
 * Total Accepted:    84.4K
 * Total Submissions: 285.4K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 *
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Return 6.
 *
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        vector<int> height(matrix[0].size(), 0);
        int maxRect = 0;

        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0; j < height.size(); j++){
                if(matrix[i][j] == '0') height[j] = 0;
                else ++height[j];
            }
            int tmp = largestRectangleArea(height);
            maxRect = max(maxRect, tmp);
            
        }
        return maxRect;
    }

    int largestRectangleArea(vector<int>& heights){
        int maxH = 0;
        int len = heights.size();
        vector<int> L(len, 0), R(len, 0);

        stack<int> st;
        for(int i = 0; i < len; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                R[st.top()] = i - st.top() - 1;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            R[st.top()] = len - 1 - st.top();
            st.pop();
        }
        for(int i = len - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                L[st.top()] = st.top() - i - 1;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            L[st.top()] = st.top() - 0;
            st.pop();
        }

        // for(int i = 0; i < len; i++){
        //     cout << i << " " << L[i] << " " << R[i] << endl;
        // }

        for(int i = 0; i < len; i++){
            maxH = max(maxH, heights[i] * (L[i] + R[i] + 1));
        }
        return maxH;
    }
};
