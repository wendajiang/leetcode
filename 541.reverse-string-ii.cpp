class Solution {
public:
    string reverseStr(string s, int k) {
        int length = s.size();
        if(k >= length) {
            reverseCore(s, 0, length - 1);
        }
        else{
            //int count = length / k;
            //int remainders = length % k;
            for(int i = 0; i < length; i ++){
                if((i / k) & 1){
                    continue;
                }else{
                    int begin = i;
                    int end = ((i + k - 1) <= length - 1) ? (i + k - 1) : length - 1;
                    reverseCore(s, begin, end);
                    i = end;
                }
            }
        }
        return s;
        
    }
    void reverseCore(string &s, int begin, int end){
        while(begin <= end){
            auto c = s[begin];
            s[begin] = s[end];
            s[end] = c;
            begin ++;
            end --;
        }
    }
};