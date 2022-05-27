/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray
 *
 * Easy (39.44%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 *
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest sum.
 *
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 *
 *
 * click to show more practice.
 *
 * More practice:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */
class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int length = nums.size();
    //     int result = INT_MIN;
    //     for(int i = 1; i < length; i++){
    //         nums[i] += nums[i - 1];
    //     }
    //     int minPrefix = 0;
    //     for(int i = 0; i < length; i++){
    //         result = std::max(result, nums[i] - minPrefix);
    //         minPrefix = std::min(minPrefix, nums[i]);
    //     }
    //     return result;
    // }
    int maxSubArray(vector<int>& nums){
    int low = 0;
    int high = nums.size() - 1;
    vector<int> result = maxSubArrayCore(nums, low, high);
    return result[2];
}

vector<int> maxSubArrayCore(vector<int>& nums, int low, int high){
    int mid = 0;
    if(high == low){
        vector<int> result;
        result.push_back(low);
        result.push_back(high);
        result.push_back(nums[low]);
        return result;
    }
    else{
        mid = (low + high) / 2;
        vector<int> left = maxSubArrayCore(nums, low, mid);
        vector<int> right = maxSubArrayCore(nums, mid + 1, high);
        vector<int> cross = findMaxCrossingSubarray(nums, low, mid, high);
        // cout << "left: ";
        // for(auto x : left){
        //     cout << x << " ";
        // }
        // cout << endl;
        // cout << "right: ";
        // for(auto x : right){
        //     cout << x << " ";
        // }
        // cout << endl;
        // cout << "cross: ";
        // for(auto x : cross){
        //     cout << x << " ";
        // }
        // cout << endl;
        if(left[2] >= right[2] && left[2] >= cross[2]){
            return left;
        }else if(right[2] >= left[2] && right[2] >= cross[2]){
            return right;
        }else{
            return cross;
        }
    }
}

vector<int> findMaxCrossingSubarray(vector<int>& nums, int low, int mid, int high){
    int leftSum = INT_MIN;
    int sum = 0;
    vector<int> agg;
    for(int i = mid; i >= low; i--){
        sum += nums[i];
        if(sum > leftSum){
            leftSum = sum;
            agg.insert(agg.begin() , i);
        }
    }
    int rightSum = INT_MIN;
    sum = 0;
    for(int i = mid + 1; i <= high; i++){
        sum += nums[i];
        if(sum > rightSum){
            rightSum = sum;
            agg.insert(agg.begin() + 1, i);
        }
    }
    agg.insert(agg.begin() + 2, leftSum + rightSum);
    agg.erase(agg.begin() + 3, agg.end());
    return agg;
}




};
