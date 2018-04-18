/*
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (26.32%)
 * Total Accepted:    111.9K
 * Total Submissions: 424.9K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * click to show corner cases.
 *
 * Corner Cases:
 *
 *
 *
 *
 *
 *
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together,
 * such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 *
 *
 */
class Solution {
public:
    // string simplifyPath(string path) {
    //     string res = "";
    //     stack<int> st;
    //     vector<string> sli;
    //     int last = 0;
    //     int cur = last + 1;
    //     while(cur < path.size()){
    //         while(path[cur] != '/')cur++;
    //         sli.push_back(path.substr(last + 1, cur - last - 1));
    //         while(path[cur] == '/') cur++;
    //         last = cur - 1;
    //     }
    //     if(last != cur - 1) sli.push_back(path.substr(last + 1, cur - last - 1));
    //     cur = 0;
    //     vector<bool> work(sli.size(), 1);
    //     while(cur < sli.size()){
    //         if(sli[cur] == ".") work[cur] = 0;
    //         if(sli[cur] == "..") {
    //             work[cur] = 0;
    //             int tmp = cur;
    //             while(tmp >= 1 && work[tmp] == 0) tmp--;
    //             work[tmp] = 0;
    //         }
    //         cur++;
    //     }
    //
    //     for(int i = 0; i < sli.size(); i++){
    //         if(work[i])
    //             res += "/" + sli[i];
    //     }
    //     if(res == "") res += "/";
    //     return res;
    // }
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss,tmp,'/')) {
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." and !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }
};
