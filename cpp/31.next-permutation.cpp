/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation
 *
 * algorithms
 * Medium (28.78%)
 * Total Accepted:    117.1K
 * Total Submissions: 406.7K
 * Testcase Example:  '[1]'
 *
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return ;
        int index = nums.size() - 1;
        while(index > 0){
            if(nums[index - 1] < nums[index]){
                break;
            }
            index--;
        }
        if(index == 0){
            reverseSort(nums, 0, nums.size() - 1);
        }else{
            int val = nums[index - 1];
            int j = nums.size() - 1;
            while(j >= index){
                if(nums[j] > val){
                    break;
                }
                j--;
            }
            swap(nums, index - 1, j);
            reverseSort(nums, index, nums.size() - 1);
        }
    }
    void reverseSort(vector<int>& nums, int begin, int end){
        while(begin < end){
            swap(nums, begin, end);
            begin ++;
            end --;
        }
    }
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
