/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr
 *
 * Easy (27.88%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""\n""'
 *
 * 
 * Implement strStr().
 * 
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size())
            return -1;
        if(needle.size() == 0)
            return 0;
        int* next = getNext(needle);
        int i = 0;
        int j = 0;
        int sLen = haystack.size();
        int pLen = needle.size();
        while(i < sLen && j < pLen){
            if(j == -1 || haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                j = next[j];
            }
        }
        if(j == pLen){
            return i - j;
        }else{
            return -1;
        }

    }

    int* getNext(string pattern){
        int *next = new int[pattern.size()];
        next[0] = -1;
        int k = -1;
        int j = 0;
        while(j < pattern.size() - 1){
            if(k == -1 || pattern[j] == pattern[k]){
                ++k;
                ++j;
                next[j] = k;
                //if(pattern[k] != pattern[j])
                  //  next[j] = k;
                //else
                  //  next[j] = next[k];
            }else{
                k = next[k];
            }
        }
        return next;
    }
};
