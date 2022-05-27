/*
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (42.34%)
 * Total Accepted:    28.3K
 * Total Submissions: 66.9K
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[ ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 *
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 *
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 *
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 *
 *
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ].
 *
 *
 *
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 *
 */
class Solution {
public:

    // //抽象成图论中各节点之间的距离，多点到多点，所以可以Floyd算法求解,简单粗暴，不过效果真的差，也就是能AC了。。。
    // // Floyd算法O(n3)，确实慢。
    // vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    //     unordered_map<string, unordered_map<string, double>> hash;
    //     for(int i = 0 ; i < equations.size(); i++){
    //         hash[equations[i].first][equations[i].second] = values[i];
    //         hash[equations[i].second][equations[i].first] = 1 / values[i];
    //     }
    //     for(auto val : hash) hash[val.first][val.first] = 1;
    //     for(auto val1 : hash){
    //         for(auto val2 : hash){
    //             for(auto val3 : hash){
    //                 if(hash[val1.first].count(val3.first)
    //             && hash[val2.first].count(val1.first))
    //                     hash[val2.first][val3.first] = hash[val2.first][val1.first] *
    //                         hash[val1.first][val3.first];
    //             }
    //         }
    //     }
    //     vector<double> ans;
    //     for(auto val : queries){
    //         ans.push_back(hash[val.first].count(val.second) ? hash[val.first][val.second] : -1);
    //     }
    //     return ans;
    // }

    /*
    确实是一道图论题，把所有常量看做点
    */

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> query) {
        unordered_map<string, vector<pair<string, double>>> table;
        vector<double> res;

        for (int i = 0; i < equations.size(); i++) {
            table[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
            table[equations[i].second].push_back(make_pair(equations[i].first, double(1.0f / values[i])));
        }

        for (int i = 0; i < query.size(); i++) {
            unordered_set<string> visited;
            visited.insert(query[i].first);
            double ans = 1;
            if (dfs(table, visited, query[i].first, query[i].second, ans))
                res.push_back(ans);
                else res.push_back(double(-1));
            }
            return res;
    }
    bool dfs(unordered_map<string, vector<pair<string, double>>>& table, unordered_set<string>& visited, string& s, string& e, double& ans) {
        if (table.count(s) == 0) return false;
        if (s == e) return true;

        for (int i = 0; i < table[s].size(); i++) {
            if (visited.count(table[s][i].first) == 0) {
                visited.insert(table[s][i].first);
                double old = ans;
                ans *= table[s][i].second;
                if (dfs(table, visited, table[s][i].first, e, ans))
                return true;
                ans = old; //当发现i节点走不通的时候，记得恢复ans并且擦去visited存的值
                visited.erase(table[s][i].first);
            }
        }
        return false;
    }
};
