/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation
 *
 * Medium (26.94%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '["18"]'
 *
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish
 * Notation.
 *
 *
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 *
 *
 *
 * Some examples:
 *
 * ⁠ ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ⁠ ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 *
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> opNum;
        auto it = tokens.begin();

        while(it != tokens.end()){
            string tmp = *it;
            it++;
            if(!isOp(tmp)){
                opNum.push_back(tmp);
            }else if(isOp(tmp)){
                if(opNum.size() < 2){
                    return -1;
                }
                int secondNum = std::stoi(opNum.back());
                opNum.pop_back();
                int firstNum = std::stoi(opNum.back());
                opNum.pop_back();
                int result = 0;
                switch (tmp[0])
                {
                case '+':
                    /* code */
                    result = firstNum + secondNum;
                    break;
                case '-':
                    /* code */
                    result = firstNum - secondNum;
                    break;
                case '*':
                    /* code */
                    result = firstNum * secondNum;
                    break;
                case '/':
                    /* code */
                    result = firstNum / secondNum;
                    break;
                default:
                    /* code */
                    break;
                }
                opNum.push_back(std::to_string(result));
            }
        }
        if(opNum.size() == 1){
            return std::stoi(opNum.back());
        }else{
            return -1;
        }
    }

    bool isOp(string s){
        if(s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'))
            return true;
        else
            return false;
    }
};
