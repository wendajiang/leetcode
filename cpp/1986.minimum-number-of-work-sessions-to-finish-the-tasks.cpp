//  Category: algorithms
//  Level: Medium
//  Percent: 33.137966%



 //  There are n tasks assigned to you. The task times are represented as an integer array tasks of length n, where the ith task takes tasks[i] hours to finish. A work session is when you work for at most sessionTime consecutive hours and then take a break.
 //  
 //  You should finish the given tasks in a way that satisfies the following conditions:
 //  
 //  
 //  	If you start a task in a work session, you must complete it in the same work session.
 //  	You can start a new task immediately after finishing the previous one.
 //  	You may complete the tasks in any order.
 //  
 //  
 //  Given tasks and sessionTime, return the minimum number of work sessions needed to finish all the tasks following the conditions above.
 //  
 //  The tests are generated such that sessionTime is greater than or equal to the maximum element in tasks[i].
 //  
 //   
 //  Example 1:
 //  
 //  Input: tasks = [1,2,3], sessionTime = 3
 //  Output: 2
 //  Explanation: You can finish the tasks in two work sessions.
 //  - First work session: finish the first and the second tasks in 1 + 2 = 3 hours.
 //  - Second work session: finish the third task in 3 hours.
 //  
 //  
 //  Example 2:
 //  
 //  Input: tasks = [3,1,3,1,1], sessionTime = 8
 //  Output: 2
 //  Explanation: You can finish the tasks in two work sessions.
 //  - First work session: finish all the tasks except the last one in 3 + 1 + 3 + 1 = 8 hours.
 //  - Second work session: finish the last task in 1 hour.
 //  
 //  
 //  Example 3:
 //  
 //  Input: tasks = [1,2,3,4,5], sessionTime = 15
 //  Output: 1
 //  Explanation: You can finish all the tasks in one work session.
 //  
 //  
 //   
 //  Constraints:
 //  
 //  
 //  	n == tasks.length
 //  	1 <= n <= 14
 //  	1 <= tasks[i] <= 10
 //  	max(tasks[i]) <= sessionTime <= 15
 //  
 
#include <bits/stdc++.h>
// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/solutions/3078601/simplest-explanation-with-traditional-pick-notpick-technique-memoization-bitmasking-c/
/**
 * @brief explanation
 * Intuition
 * Since we can't arrange the given tasks in some pattern, and apply some greedy approach, we need to try out all possible patterns.
 * We will use the tradional pick/not pick technqiue with a slight modification.
 * We will sweep through array and do the tasks which are valid (under session time limit) and not done yet. (maitaining a visited array)
 * 
 * Now will check if all tasks are done, if so: will return 1, else will start a new session: return 1 + solveNext();
 * 
 * Approach:
 * curTime -> how much time already consumed from completed tasks
 * mask -> keep track of tasks done
 * tasks -> input array
 * With these variables, we will write a function which will return minimum number of sessions required to do all tasks.
 * 
 * Steps:
 * 1. check if all true
 * 2. try out doning all valid tasks using for loop(pick/ not pick)
 * 3. take the minimum one from it as ans
 * 4. at last, check if ans remains same (=infinity), if so: start new session, else: return ans
 * 
 * Complexity:
 * time and space: O(2^n)
 * 
 */

/*
// bruce search
class Solution {
public:

    int limit;
    int allTrue;

    int solve(int curTime, int mask, vector<int> &tasks){
        if(mask == allTrue) return 1;       //if all tasks done, return 1 session required only.
        
        int minSessions = 1e9;
        for(int j=0;j<tasks.size();j++){
            if(!(mask & (1<<j)) and curTime + tasks[j] <= limit){   //check if valid and not done yet
                minSessions = min(minSessions, solve(curTime + tasks[j], mask + (1<<j), tasks));
            }
        }
        
        //no task can be done and all tasks are still not done yet, 
        //so start a new session:
        if(minSessions == 1e9){     
            minSessions = 1 + solve(0, mask, tasks);
            return minSessions;
        }
        else return minSessions;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        limit = sessionTime;
        allTrue = pow(2, tasks.size()) - 1;     // for n bits, we require 2^n - 1 number in INT.
        return solve(0, 0, tasks);
    }
};
*/
//  @lc code=start
class Solution {
public:
    int limit;
    int allTrue;
    
    vector<vector<int>> dp;
    
    int solve(int curTime, int mask, vector<int> &tasks){
        if(mask == allTrue) return 1;
        if(dp[curTime][mask] != -1) return dp[curTime][mask];
        
        int minSessions = 1e9;
        for(int j=0;j<tasks.size();j++){
            if(!(mask & (1<<j)) and curTime + tasks[j] <= limit){
                minSessions = min(minSessions, solve(curTime + tasks[j], mask + (1<<j), tasks));
            }
        }
        
        if(minSessions == 1e9){
            minSessions = 1 + solve(0, mask, tasks);
            return dp[curTime][mask] = minSessions;
        }
        else return dp[curTime][mask] = minSessions;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        limit = sessionTime;
        allTrue = pow(2, tasks.size()) - 1;
                
        int M = pow(2, tasks.size()) - 1;
        dp = vector<vector<int>> (200, vector<int>(M, -1));
        return solve(0, 0, tasks);
    }
};
//  @lc code=end
