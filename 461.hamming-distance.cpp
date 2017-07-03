class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int tmp = x ^ y;
        while(tmp){
            tmp &= (tmp - 1);
            count ++;
            // tmp = tmp - 1;
        }
        return count;
    }
};