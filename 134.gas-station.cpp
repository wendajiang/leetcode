/*
 * [134] Gas Station
 *
 * https://leetcode.com/problems/gas-station/description/
 *
 * algorithms
 * Medium (29.94%)
 * Total Accepted:    101.7K
 * Total Submissions: 339.2K
 * Testcase Example:  '[4]\n[5]'
 *
 *
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i].
 *
 *
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from station i to its next station (i+1). You begin the journey with
 * an empty tank at one of the gas stations.
 *
 *
 *
 * Return the starting gas station's index if you can travel around the circuit
 * once, otherwise return -1.
 *
 *
 *
 * Note:
 * The solution is guaranteed to be unique.
 *
 */
class Solution {
public:

    // //TLE
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int len = gas.size();
    //     for(int pos = 0; pos < len; pos ++){
    //         //从pos开始
    //         if(gas[pos] < cost[pos]) continue;
    //         else{
    //             int remaingas = gas[pos] - cost[pos];
    //             int idx = (pos + 1) % len;
    //             while(idx != pos){
    //                 remaingas += gas[idx] - cost[idx];
    //                 if(remaingas < 0) break;
    //                 idx = (idx + 1) % len;
    //             }
    //             if(idx == pos) return pos;
    //         }
    //     }
    //     return -1;
    // }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int total = 0, sum = 0;
        int index = -1;
        for(int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(sum < 0){
                sum = 0;
                index = i;
            }
        }
        return total >= 0 ? index + 1 : -1;
    }
};
