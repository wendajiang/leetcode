/*
 * @lc app=leetcode id=770 lang=cpp
 *
 * [770] Basic Calculator IV
 *
 * https://leetcode.com/problems/basic-calculator-iv/description/
 *
 * algorithms
 * Hard (54.44%)
 * Likes:    95
 * Dislikes: 940
 * Total Accepted:    6.9K
 * Total Submissions: 12.7K
 * Testcase Example:  '"e + 8 - a + 5"\n["e"]\n[1]'
 *
 * Given an expression such as expression = "e + 8 - a + 5" and an evaluation
 * map such as {"e": 1} (given in terms of evalvars = ["e"] and evalints =
 * [1]), return a list of tokens representing the simplified expression, such
 * as ["-1*a","14"]
 *
 *
 * An expression alternates chunks and symbols, with a space separating each
 * chunk and symbol.
 * A chunk is either an expression in parentheses, a variable, or a
 * non-negative integer.
 * A variable is a string of lowercase letters (not including digits.) Note
 * that variables can be multiple letters, and note that variables never have a
 * leading coefficient or unary operator like "2x" or "-x".
 *
 *
 * Expressions are evaluated in the usual order: brackets first, then
 * multiplication, then addition and subtraction.
 *
 *
 * For example, expression = "1 + 2 * 3" has an answer of ["7"].
 *
 *
 * The format of the output is as follows:
 *
 *
 * For each term of free variables with a non-zero coefficient, we write the
 * free variables within a term in sorted order lexicographically.
 *
 * For example, we would never write a term like "b*a*c", only
 * "a*b*c".
 *
 *
 * Terms have degrees equal to the number of free variables being multiplied,
 * counting multiplicity. We write the largest degree terms of our answer
 * first, breaking ties by lexicographic order ignoring the leading coefficient
 * of the term.
 *
 * For example, "a*a*b*c" has degree 4.
 *
 *
 * The leading coefficient of the term is placed directly to the left with an
 * asterisk separating it from the variables (if they exist.) A leading
 * coefficient of 1 is still printed.
 * An example of a well-formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b",
 * "4*a", "5*c", "-6"].
 * Terms (including constant terms) with coefficient 0 are not
 * included.
 *
 * For example, an expression of "0" has an output of [].
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
 * Output: ["-1*a","14"]
 *
 *
 * Example 2:
 *
 *
 * Input: expression = "e - 8 + temperature - pressure", evalvars = ["e",
 * "temperature"], evalints = [1, 12]
 * Output: ["-1*pressure","5"]
 *
 *
 * Example 3:
 *
 *
 * Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
 * Output: ["1*e*e","-64"]
 *
 *
 * Example 4:
 *
 *
 * Input: expression = "a * b * c + b * a * c * 4", evalvars = [], evalints =
 * []
 * Output: ["5*a*b*c"]
 *
 *
 * Example 5:
 *
 *
 * Input: expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c
 * - a))", evalvars = [], evalints = []
 * Output:
 * ["-1*a*a*b*b","2*a*a*b*c","-1*a*a*c*c","1*a*b*b*b","-1*a*b*b*c","-1*a*b*c*c","1*a*c*c*c","-1*b*b*b*c","2*b*b*c*c","-1*b*c*c*c","2*a*a*b","-2*a*a*c","-2*a*b*b","2*a*c*c","1*b*b*b","-1*b*b*c","1*b*c*c","-1*c*c*c","-1*a*a","1*a*b","1*a*c","-1*b*c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= expression.length <= 250
 * expression consists of lowercase English letters, digits, '+', '-', '*',
 * '(', ')', ' '.
 * expression does not contain any leading or trailing spaces.
 * All the tokens in expression are separated by a single space.
 * 0 <= evalvars.length <= 100
 * 1 <= evalvars[i].length <= 20
 * evalvars[i] consists of lowercase English letters.
 * evalints.length == evalvars.length
 * -100 <= evalints[i] <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    //两个不同的变量名称str1,str2按照字典序组合为一个新的变量名称newVarName
    //例如 str1 = a*c, str2 = b*d ,组合后得到 a*b*c*d
    string combineNewVarName(string str1, string str2) {
        vector<string> A;

        str1 += '*';
        int pos = str1.find("*", 0);
        while (pos != str1.npos) {
            string temp = str1.substr(0, pos);
            A.push_back(temp);
            str1 = str1.substr(pos + 1, str1.size());
            pos = str1.find("*", 0);
        }

        str2 += '*';
        pos = str2.find("*", 0);
        while (pos != str2.npos) {
            string temp = str2.substr(0, pos);
            A.push_back(temp);
            str2 = str2.substr(pos + 1, str2.size());
            pos = str2.find("*", 0);
        }

        sort(A.begin(), A.end());
        string newVarName = A[0];
        for (int i = 1; i < A.size(); i++) {
            newVarName += "*";
            newVarName += A[i];
        }
        return newVarName;
    }

    //从字符串idx位置开始，获取一个新操作数
    map<string, int> getOne(string &str, int& idx) {
        map<string, int> res;
        res["@"] = 0;
        int n = str.size();
        if (idx >= n) return res;
        int start = idx;
        if (str[idx] == '(') { //将括号表达式的计算结果返回
            stack<int> s;
            s.push(idx++);
            while (idx < n && !s.empty()) {
                if (str[idx] == '(') s.push(idx);
                if (str[idx] == ')') s.pop();
                idx++;
            }
            string substr = str.substr(start + 1, idx - start - 2);
            res = calculator(substr);
        } else if (isdigit(str[idx])) { //操作数是一个数字
            while (idx < n && isdigit(str[idx])) idx++;
            string val = str.substr(start, idx - start);
            res["@"] = stoi(val);
        } else { //操作数是一个变量
            while (idx < n && str[idx] != ' ') idx++;
            string varName = str.substr(start, idx - start);
            if (hashtable.count(varName)) res["@"] = hashtable[varName];
            else { res[varName] = 1; }
        }
        idx += 1;
        return res;
    }

    //定义新的加法操作
    map<string, int> add(map<string, int> &A, map<string, int> &B) {
        map<string, int> C = A;
        for (auto &x:B) {
            if (C.count(x.first)) {
                C[x.first] += x.second;
            } else {
                C[x.first] = x.second;
            }
        }
        return C;
    }

    //定义新的减法操作
    map<string, int> sub(map<string, int> &A, map<string, int> &B) {
        map<string, int> C = A;
        for (auto &x:B) {
            if (C.count(x.first)) {
                C[x.first] -= x.second;
            } else {
                C[x.first] = -x.second;
            }
        }
        return C;
    }

    //定义新的乘法操作
    map<string, int> mul(map<string, int> &A, map<string, int> &B) {
        map<string, int> C;
        C["@"] = 0;
        for (auto &a:A) {
            for (auto &b:B) { 
                if (a.first == "@") { // a是常数
                    if (C.count(b.first)) {
                        C[b.first] += a.second * b.second;
                    } else {
                        C[b.first] = a.second * b.second;
                    }
                } else if (b.first == "@") { //b是常数
                    if (C.count(a.first)) {
                        C[a.first] += a.second * b.second;
                    } else {
                        C[a.first] = a.second * b.second;
                    }
                } else { //a b 都不是常数，则需要合成新的变量名称
                    string newVarName = combineNewVarName(a.first, b.first); 
                    if (C.count(newVarName)) {
                        C[newVarName] += a.second * b.second;
                    } else {
                        C[newVarName] = a.second * b.second;
                    }
                }
            }
        }
        return C;
    }

    //基于新元素操作的计算器
    map<string,int> calculator(string expression) {
        if(expression.empty()) return {};
        map<string, int> res, curRes;
        res["@"] = 0;
        curRes["@"] = 0;
        expression += " +";
        int n = expression.size();
        char op = '+';
        for (int i = 0; i < n; i += 2) {
            map<string, int> x = getOne(expression, i);
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || i == n - 1) {
                switch (op) {
                    case '+':
                        curRes = add(curRes, x);
                        break;
                    case '-':
                        curRes = sub(curRes, x);
                        break;
                    case '*':
                        curRes = mul(curRes, x);
                        break;
                }
                if (expression[i] == '+' || expression[i] == '-' || i == n - 1) {
                    res = add(res, curRes);
                    curRes.clear();
                    curRes["@"] = 0;
                }
                op = expression[i];
            }
        }
        return res;
    }

public:
    unordered_map<string,int> hashtable;
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        //使用哈希表将变量与其值对应起来
        for (int i = 0; i < evalvars.size(); i++) {
            hashtable[evalvars[i]] = evalints[i];
        }

        //使用基于新操作数的计算器计算出表达式的结果，结果以新操作数的形式返回
        map<string, int> tree = calculator(expression);

        //整理、排序输出最终的结果
        //排序的规则是：变量排在常数前面，变量名称中含有的子变量越多，排序越靠前；变量名称中的子变量数目相同，则按照字典序进行排序
        // 比如运算结果：-99*z*z*z*z*z 9*a*b*c*d 6*b*b*b 5*a*b 1*a 2*b 3*c 18 是合法的排序
        vector<pair<int,string>> sortVec;
        for(auto &x:tree){
            if (x.second != 0 && x.first != "@") {
                string str = x.first;
                str += '*';
                int cnt = 0;
                int pos = str.find("*", 0);
                while (pos != str.npos) {
                    cnt++;
                    str = str.substr(pos + 1, str.size());
                    pos = str.find("*", 0);
                }
                sortVec.push_back({cnt, x.first});
            }
        }

        sort(sortVec.begin(), sortVec.end(),[](pair<int,string> A, pair<int, string> B){
            return A.first != B.first ? A.first > B.first : A.second < B.second;
        });

        vector<string> ans(sortVec.size());
        int constant = tree["@"];
        for (int i = 0; i < sortVec.size(); i++) {
            ans[i] = to_string(tree[sortVec[i].second]) + "*" + sortVec[i].second;
        }

        if (constant != 0) ans.push_back(to_string(constant));

        return ans;
    }
};
// @lc code=end
