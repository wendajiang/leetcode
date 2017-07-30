/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii
 *
 * Easy (44.62%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[]\n[]'
 *
 *
 * Given two arrays, write a function to compute their intersection.
 *
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 *
 * Note:
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 *
 *
 * Follow up:
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> m1(nums1.begin(), nums1.end());
        unordered_multiset<int> m2(nums2.begin(), nums2.end());
        vector<int> res;
        for (auto a : nums2)
            if (m1.count(a)) {
                int count = std::min(m1.count(a), m2.count(a)); 
                while(count){
                    res.push_back(a);
                    count--;
                }
                m1.erase(a);
            }
        return res;
    }
};
