/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion
 *
 * Medium (26.64%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""\n1'
 *
 * 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string result;
        int length = s.size();
        int index = 0;
        int gap = numRows * 2 - 2;
        for(int i = 0; i < numRows; i++){
            if(i == 0 || i == numRows - 1){
                index = i;
                while(index < length){
                    result.push_back(s[index]);
                    index += gap;
                }
            }else {
                int first = gap - 2 * i;
                int second = gap - first;
                bool pad = true;
                index = i;
                while(index < length){
                    result.push_back(s[index]);
                    if(pad){
                        index += first;
                        pad = false;
                    }else{
                        index += second;
                        pad = true;
                    }
                }
            }
        }
        return result;
    }
};
