/*
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch
 *
 * Easy (44.77%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 *
 * For example, the above binary watch reads "3:25".
 *
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 *
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 *
 *
 * Note:
 *
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 *
 *
 */
class Solution {
public:
    // vector<string> readBinaryWatch(int num) {
    //     vector<string> res;
    //     vector<vector<bool>> solution;
    //     vector<bool> binary;
    //     int count1 = 0;
    //     dfs(num, solution, binary, count1);
    //     for(auto e : solution){
    //         string tmp = change2String(e);
    //         if(tmp.size() > 0){
    //             res.push_back(tmp);
    //         }
    //     }
    //     return res;
    // }
    //
    // void dfs(int num, vector<vector<bool>>& solution,vector<bool>binary, int count1){
    //     if(binary.size() >= 10 && count1 < num){
    //         return;
    //     }else if(binary.size() == 10 && count1 == num){
    //         solution.push_back(binary);
    //         return;
    //     }else if(binary.size() < 10 && count1 == num){
    //         while(binary.size() < 10){
    //             binary.push_back(false);
    //         }
    //         solution.push_back(binary);
    //         return;
    //     }
    //     binary.push_back(false);
    //     dfs(num, solution, binary , count1);
    //     binary.pop_back();
    //     binary.push_back(true);
    //     dfs(num, solution, binary, count1 + 1);
    //     binary.pop_back();
    // }
    // string change2String(vector<bool> watch){
    //     string res;
    //     int hour = 0;
    //     int minute = 0;
    //     for(int i = 3; i >=0; i--){
    //         if(watch[i]){
    //             hour += std::pow(2, 3 - i);
    //         }
    //     }
    //     if(hour <= 11) res.append(to_string(hour));
    //     if(res.size() > 0) res.push_back(':');
    //     for(int i = 9; i >= 4; i--){
    //         if(watch[i])
    //             minute += std::pow(2, 9 - i);
    //     }
    //     if(minute <= 59 && minute >= 10) res.append(to_string(minute));
    //     else if(minute < 10) res.append("0" + to_string(minute));
    //     if(res.size() >= 4)
    //         return res;
    //     else return "";
    // }

    // solution的方法，DFS深度较浅，使用了循环，0ms
    vector<int> hour = {1, 2, 4, 8}, minute = {1, 2, 4, 8, 16, 32};
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        helper(res, make_pair(0, 0), num, 0);
        return res;
    }

    void helper(vector<string>& res, pair<int, int> time, int num, int start_point) {
        if (num == 0) {
            res.push_back(to_string(time.first) +  (time.second < 10 ?  ":0" : ":") + to_string(time.second));
            return;
        }
        for (int i = start_point; i < hour.size() + minute.size(); i ++)
            if (i < hour.size()) {
                time.first += hour[i];
                if (time.first < 12)     helper(res, time, num - 1, i + 1);     // "hour" should be less than 12.
                time.first -= hour[i];
            } else {
                time.second += minute[i - hour.size()];
                if (time.second < 60)    helper(res, time, num - 1, i + 1);     // "minute" should be less than 60.
                time.second -= minute[i - hour.size()];
            }
    }
};
