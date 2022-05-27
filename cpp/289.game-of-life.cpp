/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (57.59%)
 * Likes:    2372
 * Dislikes: 319
 * Total Accepted:    218.8K
 * Total Submissions: 379.6K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to Wikipedia's article: "The Game of Life, also known simply as
 * Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 * 
 * The board is made up of an m x n grid of cells, where each cell has an
 * initial state: live (represented by a 1) or dead (represented by a 0). Each
 * cell interacts with its eight neighbors (horizontal, vertical, diagonal)
 * using the following four rules (taken from the above Wikipedia
 * article):
 * 
 * 
 * Any live cell with fewer than two live neighbors dies as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population.
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 * 
 * 
 * The next state is created by applying the above rules simultaneously to
 * every cell in the current state, where births and deaths occur
 * simultaneously. Given the current state of the m x n grid board, return the
 * next state.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
 * Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [[1,1],[1,0]]
 * Output: [[1,1],[1,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 25
 * board[i][j] is 0 or 1.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Could you solve it in-place? Remember that the board needs to be updated
 * simultaneously: You cannot update some cells first and then use their
 * updated values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches upon the border of the array (i.e., live cells reach the border).
 * How would you address these problems?
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) return ;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int x = get_live_or_dead(board, i, j, board.size(), board[i].size());
                board[i][j] = x << 1 | board[i][j];
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1;
            }
        }
    }

    int get_live_or_dead(vector<vector<int>>& board, int i, int j, int ilen, int jlen) {
        int val = board[i][j] & 0x1;
        int live_cnt = 0;
        for (int k = 0; k < 8; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            if (next_i >= 0 && next_i < ilen && next_j >= 0 && next_j < jlen
                && board[next_i][next_j] & 0x1) {
                live_cnt++;
            }
        }
        if (val) {
            if(live_cnt == 2 || live_cnt == 3) return 1;
            else return 0;
        }
        else {
            if (live_cnt == 3) return 1;
            else return 0;
        }
    }
};
// @lc code=end

