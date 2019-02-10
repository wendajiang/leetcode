/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (28.12%)
 * Total Accepted:    174.9K
 * Total Submissions: 621.6K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * Example:
 *
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 *
 */
class Solution {
public:
    // //最后一个case会超时
    // int dx[4] = {0, 0, 1, -1};
    // int dy[4] = {-1, 1, 0, 0};
    // bool exist(vector<vector<char>>& board, string word) {
    //     if(word.size() == 0) return true;
    //     int m = board.size(), n = board[0].size();
    //     vector<vector<bool>> vis(m, vector<bool>(n, 0));
    //     vector<vector<bool>> tmp(m, vector<bool>(n, 0));
    //     vector<pair<int, int>> s;
    //     for(int i = 0; i < board.size(); i++){
    //         for(int j = 0; j < board[i].size(); j++){
    //             bool flag = false;
    //             vis = tmp;
    //             dfs(board, vis, 0, make_pair(i, j), word, flag);
    //             if(flag) return true;
    //         }
    //     }
    //     return false;
    // }
    //
    // void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int step, pair<int, int> cur, string& word, bool &flag){
    //     if(step == word.size() - 1 && word[step] == board[cur.first][cur.second]){
    //         flag = true;
    //         return;
    //     }
    //     int x = cur.first;
    //     int y = cur.second;
    //     if(word[step] == board[cur.first][cur.second]){
    //         vis[x][y] = 1;
    //         for(int i = 0; i < 4; i++){
    //             int nextx = x + dx[i];
    //             int nexty = y + dy[i];
    //             if(nextx >= 0 && nextx < board.size()
    //             && nexty >= 0 && nexty < board[0].size()
    //             && vis[nextx][nexty] == 0
    //             && board[nextx][nexty] == word[step + 1]){
    //                 dfs(board, vis, step + 1, make_pair(nextx, nexty), word, flag);
    //             }
    //         }
    //         vis[x][y] = 0;
    //     }
    //
    // }


    //discuss中的答案
    bool exist(vector<vector<char>>& board, string word){
        m = board.size();
        n = board[0].size();
        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                if(isFound(board, word.c_str(), x, y))
                    return true;
            }
        }
        return false;
    }

private:
    int m;
    int n;
    bool isFound(vector<vector<char>>& board, const char* w, int x, int y){
        if(x < 0 || y < 0 || y >= n || x >= m || board[x][y] == '\0' || *w!= board[x][y])
            return false;
        if(*(w + 1) == '\0') return true;
        char t = board[x][y];
        board[x][y] = '\0';
        if(isFound(board, w + 1, x - 1, y) || isFound(board, w + 1, x + 1, y)
        || isFound(board, w + 1, x, y - 1) || isFound(board, w + 1, x, y + 1))
            return true;
        board[x][y] = t;
        return false;
    }
};
