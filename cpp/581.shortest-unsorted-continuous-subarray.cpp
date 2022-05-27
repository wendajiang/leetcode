//Given an integer array, you need to find one continuous subarray that if you o
//nly sort this subarray in ascending order, then the whole array will be sorted i
//n ascending order, too. 
//
// You need to find the shortest such subarray and output its length. 
//
// Example 1: 
// 
//Input: [2, 6, 4, 8, 10, 9, 15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the 
//whole array sorted in ascending order.
// 
// 
//
// Note: 
// 
// Then length of the input array is in range [1, 10,000]. 
// The input array may contain duplicates, so ascending order here means <=. 
// 
// Related Topics Array 
// 👍 2695 👎 138

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -2;
        int n = nums.size();
        int left = nums[0], right = nums[n - 1];
        for (int i = 1; i < n; i++) {
            left = std::max(left, nums[i]);
            right = std::min(right, nums[n - 1 - i]);
            if (left != nums[i]) end = i;
            if (right != nums[n - 1 - i]) start = n - 1 - i;
        }
        return end - start + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    vector<int> input{2,1};
    Solution ss;
    int res = ss.findUnsortedSubarray(input);
    std::cout << res << endl;

    return 0;
}