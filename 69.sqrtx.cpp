/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx
 *
 * Easy (27.67%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '0'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 */
class Solution {
public:
    //牛顿法
    const float EPS = 0.000000001;
    // int mySqrt(int x) {
    //     if(x == 0)return x;
    //     float dividend = x;
    //     float val = x;
    //     float last;
    //     do{
    //         last = val;
    //         val = (val + dividend/val) / 2;// 关键代码
    //     }while (abs(val - last) > EPS);
    //     int result = val;
    //     if(result * result > x){
    //         result --;
    //     }
    //     return result;
    // }

    int mySqrt(int x) {
        if (x == 0) return x;
        double r = x;
        while (abs(r * r - x) > 0.1) {
            r = r - (r * r - x) / (2 * r);
        }

        return r;
    }

    // //http://www.cnblogs.com/ECJTUACM-873284962/p/6536576.html
    // int sqrt(float x) { 
        // if(x == 0) return 0; 
        // float result = x; 
        // float xhalf = 0.5f*result; 
        // int i = *(int*)&result; 
        // i = 0x5f375a86- (i>>1); // what the fuck? 
        // result = *(float*)&i; 
        // result = result*(1.5f-xhalf*result*result); // Newton step, repeating increases accuracy 
        // result = result*(1.5f-xhalf*result*result); 
        // return 1.0f/result;
    // }
};
