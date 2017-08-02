/*
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers
 *
 * Easy (29.94%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * Suppose you have a long flowerbed in which some of the plots are planted and
 * some are not. However, flowers cannot be planted in adjacent plots - they
 * would compete for water and both would die.
 *
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means
 * empty and 1 means not empty), and a number n, return if n new flowers can be
 * planted in it without violating the no-adjacent-flowers rule.
 *
 * Example 1:
 *
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 *
 *
 *
 * Note:
 *
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 *
 *
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int count = 0;
        int countzero = 0;
        int start = 0;
        int end = len - 1;
        while(!flowerbed[start] && start < len){
            start++;
        }
        if(start == len){
            return n <= (start - 1) / 2 + 1;
        }
        while(!flowerbed[end] && start <= end){
            end--;
        }
        if(start != 0){
            count += start / 2;
        }
        if(end != len - 1){
            count += (len - 1 - end) / 2;
        }
        for(int i = start; i <= end; i++){
            if(flowerbed[i]){
                if(countzero)
                    count += (countzero - 1) / 2;
                countzero = 0;
            }else{
                countzero ++;
            }
        }
        return n <= count;
    }
};
