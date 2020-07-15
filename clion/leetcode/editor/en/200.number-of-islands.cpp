//Given a 2d grid map of '1's (land) and '0's (water), count the number of islan
//ds. An island is surrounded by water and is formed by connecting adjacent lands 
//horizontally or vertically. You may assume all four edges of the grid are all su
//rrounded by water. 
//
// Example 1: 
//
// 
//Input:
//11110
//11010
//11000
//00000
//
//Output: 1
// 
//
// Example 2: 
//
// 
//Input:
//11000
//11000
//00100
//00011
//
//Output: 3
// Related Topics Depth-first Search Breadth-first Search Union Find 
// 👍 5581 👎 193

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> set;
    int find(int x)
    {
        if(x!=set[x]) set[x] = find(set[x]);
        return set[x];
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = m;
        if (n > 0) n = grid[0].size();
        else return 0;
        for (int i = 0 ; i < m * n; i++) set.push_back(i);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = i * n + j;
                if(grid[i][j] == '0')
                {
                    set[x] = -1;
                    continue;
                }
                if(i != 0 && grid[i-1][j] == '1')
                {
                    int y = (i - 1) * n + j;
                    set[find(x)] = find(y);
                }
                if(j != 0 && grid[i][j-1] == '1')
                {
                    int y = i * n + j -1;
                    set[find(x)] = find(y);
                }
            }
        }
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 0 ;i < m * n ; i++)
        {
            if(set[i] == -1) continue;
            int y = find(i);
            if(!mp[y])
            {
                res++;
                mp[y] = 1;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution so;
    vector<vector<char>> testcase = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    int ret = so.numIslands(testcase);
    for (int i = 0 ; i < testcase.size(); i++) {
        for (int j = 0; j < testcase[i].size(); j++) {
            cout << testcase[i][j] << endl;
        }
    }
    for (int i = 0; i < so.set.size(); i++) {
        cout << so.set[i] << " ";
    }
    cout << endl;
    return 0;
}