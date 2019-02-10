class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int tmp = 0;
        bool pnFlag = false;
        if(x >= 0){
            tmp = x;
            pnFlag = true;
        }else{
            tmp = -x;
            pnFlag = false;
        }
        int ans = 0;
        while(tmp){
            int temp = ans * 10 + tmp % 10;
            if(temp / 10 != ans)
                return 0;
            ans = temp;
            tmp /= 10;
        }
        result = ans;
        if(!pnFlag)
            result = -result;
        return result;
        
        
    }
};