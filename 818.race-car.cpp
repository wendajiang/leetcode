/*
 * [836] Race Car
 *
 * https://leetcode.com/problems/race-car/description/
 *
 * algorithms
 * Hard (26.48%)
 * Total Accepted:    2.1K
 * Total Submissions: 8K
 * Testcase Example:  '3'
 *
 * Your car starts at position 0 and speed +1 on an infinite number line.
 * (Your car can go into negative positions.)
 *
 * Your car drives automatically according to a sequence of instructions A
 * (accelerate) and R (reverse).
 *
 * When you get an instruction "A", your car does the following: position +=
 * speed, speed *= 2.
 *
 * When you get an instruction "R", your car does the following: if your speed
 * is positive then speed = -1 , otherwise speed = 1.  (Your position stays the
 * same.)
 *
 * For example, after commands "AAR", your car goes to positions 0->1->3->3,
 * and your speed goes to 1->2->4->-1.
 *
 * Now for some target position, say the length of the shortest sequence of
 * instructions to get there.
 *
 *
 * Example 1:
 * Input:
 * target = 3
 * Output: 2
 * Explanation:
 * The shortest instruction sequence is "AA".
 * Your position goes from 0->1->3.
 *
 *
 *
 * Example 2:
 * Input:
 * target = 6
 * Output: 5
 * Explanation:
 * The shortest instruction sequence is "AAARA".
 * Your position goes from 0->1->3->7->7->6.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= target <= 10000.
 *
 */
class Solution {
public:

    // /*
    // BFS 对set中key值有一个hack，只需要记录存在往回走的位置
    // 就是掉头的位置
    // 然后里面有一些剪枝
    // bfs反正可以了
    // */
    // int racecar(int target) {
    //     int position = 0;
    //     int speed = 1;
    //     queue<pair<int, int>> Q;
    //     Q.push({0, 1});
    //     //记录已经vis状态
    //     unordered_set<int> u_st;
    //     u_st.insert({0, 2});
    //     int steps = 0;
    //     while(!Q.empty()) {
    //         int size = Q.size();
    //         while(size -- ) {
    //             auto p = Q.front(); Q.pop();
    //             int pos = p.first;
    //             int speed = p.second;
    //             pair<int, int> p1 = {pos + speed, speed * 2};
    //             if(p1.first == target) return steps + 1;
    //             if(p1.first > 0 && p1.first + speed < 2 * target)
    //                 Q.push(p1);
    //
    //             int speed2 = speed > 0 ? -1 : 1;
    //             pair<int, int> p2 = {pos, speed2};
    //             int key = (pos << 2) | (speed2 + 1);
    //             if(!u_st.count(key) && p2.first >= target / 2){
    //                 Q.push(p2);
    //                 u_st.insert(key);
    //             }
    //         }
    //         steps++;
    //     }
    //     return -1;
    // }


    //DP solution
    //记忆化搜索的问题 dp 有点难想
    int racecar(int target){
        m_ = vector<int>(target + 1, 0);
        return dp(target);
    }

private:
    vector<int> m_;
    int dp(int t){
        if(m_[t] > 0) return m_[t];
        int n = ceil(log2(t + 1));
        //AAA... (nA) best case
        if(1 << n == t + 1) return m_[t] = n;
        //AAA..AR (nA + 1R) + dp(left)
        m_[t] = n + 1 + dp((1 << n) - 1 - t);
        for(int m = 0; m < n - 1; m++){
            int cur = (1 << (n - 1)) - (1 << m);
            //AA...ARA...AR (n - 1A + 1R + mA + 1R) + dp(left)
            m_[t] = min(m_[t], n + m + 1 + dp(t - cur));
        }
        return m_[t];
    }
};
