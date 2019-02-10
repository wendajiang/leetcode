/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku
 *
 * algorithms
 * Medium (35.62%)
 * Total Accepted:    124.2K
 * Total Submissions: 347.7K
 * Testcase Example:  '[".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]'
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 *
 *
 *
 * A partially filled sudoku which is valid.
 *
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only
 * the filled cells need to be validated.
 *
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i ++){
            unordered_map<char, bool> m1;   //check i_th row
            unordered_map<char, bool> m2;   //check i_th column
            unordered_map<char, bool> m3;   //check i_th subgrid
            for(int j = 0; j < 9; j ++)
            {
                if(board[i][j] != '.')
                {
                    if(m1[board[i][j]] == true)
                        return false;
                    m1[board[i][j]] = true;
                }
                if(board[j][i] != '.')
                {
                    if(m2[board[j][i]] == true)
                        return false;
                    m2[board[j][i]] = true;
                }
                if(board[i/3*3+j/3][i%3*3+j%3] != '.')
                {
                    if(m3[board[i/3*3+j/3][i%3*3+j%3]] == true)
                        return false;
                    m3[board[i/3*3+j/3][i%3*3+j%3]] = true;
                }
            }
        }
        return true;
    }
};
