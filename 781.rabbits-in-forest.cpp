/*
 * [797] Rabbits in Forest
 *
 * https://leetcode.com/problems/rabbits-in-forest/description/
 *
 * algorithms
 * Medium (49.42%)
 * Total Accepted:    4.3K
 * Total Submissions: 8.7K
 * Testcase Example:  '[1,0,1,0,0]'
 *
 * In a forest, each rabbit has some color. Some subset of rabbits (possibly
 * all of them) tell you how many other rabbits have the same color as them.
 * Those answers are placed in an array.
 *
 * Return the minimum number of rabbits that could be in the forest.
 *
 *
 * Examples:
 * Input: answers = [1, 1, 2]
 * Output: 5
 * Explanation:
 * The two rabbits that answered "1" could both be the same color, say red.
 * The rabbit than answered "2" can't be red or the answers would be
 * inconsistent.
 * Say the rabbit that answered "2" was blue.
 * Then there should be 2 other blue rabbits in the forest that didn't answer
 * into the array.
 * The smallest possible number of rabbits in the forest is therefore 5: 3 that
 * answered plus 2 that didn't.
 *
 * Input: answers = [10, 10, 10]
 * Output: 11
 *
 * Input: answers = []
 * Output: 0
 *
 *
 * Note:
 *
 *
 * answers will have length at most 1000.
 * Each answers[i] will be an integer in the range [0, 999].
 *
 */
class Solution {
public:

    /*
    If x+1 rabbits have same color, then we get x+1 rabbits who all answer x.
    now n rabbits answer x.
    If n%(x+1)==0, we need n/(x+1) groups of x+1 rabbits.
    If n%(x+1)!=0, we need n/(x+1) + 1 groups of x+1 rabbits.

    the number of groups is math.ceil(n/(x+1)) and it equals to (n+i)/(i+1) , which is more elegant.
    */
    int numRabbits(vector<int>& answers) {
        map<int, int> mp;
        for(int num : answers) mp[num]++;
        int res = 0;
        for(auto p : mp){
            // if(p.second % (p.first + 1) == 0) res += ((p.second / (p.first + 1))) * (p.first + 1);
            // else res += ((p.second / (p.first + 1)) + 1) * (p.first + 1);
            res += (p.second + p.first) / (p.first + 1) * (p.first + 1);
        }
        return res;
    }
};
