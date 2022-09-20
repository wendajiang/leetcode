//  Category: algorithms
//  Level: Hard
//  Percent: 44.080334%

//  Given an array of integers arr, you are initially positioned at the first
//  index of the array.
//
//  In one step you can jump from index i to index:
//
//
//  	i + 1 where: i + 1 < arr.length.
//  	i - 1 where: i - 1 >= 0.
//  	j where: arr[i] == arr[j] and i != j.
//
//
//  Return the minimum number of steps to reach the last index of the array.
//
//  Notice that you can not jump outside of the array at any time.
//
//   
//  Example 1:
//
//  Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
//  Output: 3
//  Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that
//  index 9 is the last index of the array.
//
//
//  Example 2:
//
//  Input: arr = [7]
//  Output: 0
//  Explanation: Start index is the last index. You do not need to jump.
//
//
//  Example 3:
//
//  Input: arr = [7,6,9,6,9,6,9,7]
//  Output: 1
//  Explanation: You can jump directly from index 0 to index 7 which is last
//  index of the array.
//
//
//   
//  Constraints:
//
//
//  	1 <= arr.length <= 5 * 10⁴
//  	-10⁸ <= arr[i] <= 10⁸
//
#include <bits/stdc++.h>
using namespace std;
//  @lc code=start
class Solution {
   public:
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1) return 0;
        map<int, vector<int>> mp;
        vector<bool> vis(arr.size(), false);
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int> cur;
        int level = 0;
        cur.push_back(0);
        vis[0] = true;
        while (!cur.empty()) {
            vector<int> next;
            for (auto i : cur) {
                if (i == arr.size() - 1) return level;
                if (i - 1 >= 0 && !vis[i - 1]) {
                    next.push_back(i - 1);
                    vis[i - 1] = true;
                }
                if (i + 1 < arr.size() && !vis[i + 1]) {
                    next.push_back(i + 1);
                    vis[i + 1] = true;
                }
                for (auto eq : mp[arr[i]]) {
                    if (eq == i - 1 || eq == i + 1 || vis[eq]) {
                        continue;
                    } else {
                        next.push_back(eq);
                        vis[eq] = true;
                    }
                }
                mp.erase(arr[i]);
            }
            cur = next;
            level++;
        }
        return level;
    }
};
//  @lc code=end
