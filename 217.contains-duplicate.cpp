/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate
 *
 * Easy (45.52%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]'
 *
 *
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 *
 */
class Solution {
public:
    //sort
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return false;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }

    // //map
    // bool containsDuplicate(vector<int>& nums) {
    //     map<int, bool> myMap;
    //     // unordered_map<int, bool> myMap;
    //     for (auto& num: nums) {
    //         if (myMap.find(num) != myMap.end())
    //             return true;
    //         else
    //             myMap[num] = true;
    //     }
    //     return false;
    // }

    // //mutimap
    // bool containsDuplicate(vector<int>& nums) {
    //     multimap<int, bool> myMap;
    //     // unordered_multimap<int, bool> myMap;
    //     for (auto& num: nums) {
    //         if (myMap.find(num) != myMap.end())
    //             return true;
    //         myMap.insert(make_pair(num, true));
    //     }
    //     return false;
    // }

    // //set
    // bool containsDuplicate(vector<int>& nums) {
    //     set<int> mySet;
    //     // unordered_set<int> mySet;
    //     // multiset<int> mySet;
    //     // unordered_multiset<int> mySet;
    //     for (auto& num: nums) {
    //         if (mySet.find(num) != mySet.end())
    //             return true;
    //         mySet.insert(num);
    //     }
    //     return false;
    // }
};
