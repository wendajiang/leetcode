/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array
 *
 * Medium (38.96%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[1]\n1'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 *
 * Note:
 * You may assume k is always valid, 1 ? k ? array's length.
 *
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size() - 1, k);
    }
    int findKthLargest(vector<int>& nums, int start, int end, int k){
        if(start == end) return nums[start];
        int q = partition(nums, start, end);
        int interval = end - q + 1;
        if(interval == k)
            return nums[q];
        if(interval > k){
            return findKthLargest(nums, q + 1, end, k);
        }else{
            return findKthLargest(nums, start, q - 1, k - interval);
        }
    }
    int partition(vector<int>& nums, int start, int end){
        int x = nums[end];
        int i = start - 1;
        for(int j = start; j < end; j++){
            if(nums[j] <= x){
                i++;
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
        }
        nums[end] = nums[++i];
        nums[i] = x;
        return i;
    }
};
