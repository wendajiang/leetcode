/*
 * @lc app=leetcode id=715 lang=cpp
 *
 * [715] Range Module
 *
 * https://leetcode.com/problems/range-module/description/
 *
 * algorithms
 * Hard (42.22%)
 * Likes:    778
 * Dislikes: 60
 * Total Accepted:    35.3K
 * Total Submissions: 83.7K
 * Testcase Example:  '["RangeModule","addRange","removeRange","queryRange","queryRange","queryRange"]\n' +
  '[[],[10,20],[14,16],[10,14],[13,15],[16,17]]'
 *
 * A Range Module is a module that tracks ranges of numbers. Design a data
 * structure to track the ranges represented as half-open intervals and query
 * about them.
 *
 * A half-open interval [left, right) denotes all the real numbers x where left
 * <= x < right.
 *
 * Implement the RangeModule class:
 *
 *
 * RangeModule() Initializes the object of the data structure.
 * void addRange(int left, int right) Adds the half-open interval [left,
 * right), tracking every real number in that interval. Adding an interval that
 * partially overlaps with currently tracked numbers should add any numbers in
 * the interval [left, right) that are not already tracked.
 * boolean queryRange(int left, int right) Returns true if every real number in
 * the interval [left, right) is currently being tracked, and false
 * otherwise.
 * void removeRange(int left, int right) Stops tracking every real number
 * currently being tracked in the half-open interval [left, right).
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["RangeModule", "addRange", "removeRange", "queryRange", "queryRange",
 * "queryRange"]
 * [[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
 * Output
 * [null, null, null, true, false, true]
 *
 * Explanation
 * RangeModule rangeModule = new RangeModule();
 * rangeModule.addRange(10, 20);
 * rangeModule.removeRange(14, 16);
 * rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is
 * being tracked)
 * rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03,
 * 14.17 in [13, 15) are not being tracked)
 * rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17)
 * is still being tracked, despite the remove operation)
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= left < right <= 10^9
 * At most 10^4 calls will be made to addRange, queryRange, and removeRange.
 *
 *
 */

// @lc code=start
// class RangeModule {
// public:
    // RangeModule() {

    // }

    // void addRange(int left, int right) {
        // vector<pair<int, int>> new_ranges;
        // bool inserted = false;
        // for (const auto &p : ranges) {
            // if (p.first > right && !inserted) {
                // new_ranges.emplace_back(left, right);
                // inserted = true;
            // }
            // if (p.second < left || p.first > right) {
                // new_ranges.push_back(p);
            // } else {
                // left = min(left, p.first);
                // right = max(right, p.second);
            // }
        // }
        // if (!inserted) new_ranges.emplace_back(left, right);
        // ranges.swap(new_ranges);
    // }

    // bool queryRange(int left, int right) {
        // const int n = ranges.size();
        // int l = 0;
        // int r = n - 1;
        // while(l <= r) {
            // int m = l + ((r - l) >> 1);
            // if (ranges[m].second < left) {
                // l = m + 1;
            // } else if (ranges[m].first > right) {
                // r = m - 1;
            // } else {
                // return ranges[m].first <= left && ranges[m].second >= right;
            // }
        // }
        // return false;
    // }

    // void removeRange(int left, int right) {
        // vector<pair<int, int>> new_ranges;
        // for (auto &p : ranges) {
            // if (p.second <= left || p.first >= right) {
                // new_ranges.push_back(p);
            // } else {
                // if (p.first < left) {
                    // new_ranges.emplace_back(p.first, left);
                // }
                // if (p.second > right) {
                    // new_ranges.emplace_back(right, p.second);
                // }
            // }
        // }
        // ranges.swap(new_ranges);
    // }
// private:
    // vector<pair<int, int>> ranges;
// };

class RangeModule{
public:
    RangeModule() {}

    void addRange(int left, int right) {
        IT l, r;
        getOverlapRanges(left, right, l, r);
        if (l != r) {
            auto last = r; --last;
            left = min(left, l->first);
            right = max(right, last->second);
            ranges.erase(l, r);
        }

        ranges[left] = right;

    }

    bool queryRange(int left, int right) {
        IT l, r;
        getOverlapRanges(left, right, l, r);
        if (l == r) return false;
        return l->first <= left && l->second >= right;
    }

    void removeRange(int left, int right) {
        IT l, r;
        getOverlapRanges(left, right, l, r);
        if (l == r) return;
        auto last = r; --last;
        int start = min(left, l->first);
        int end = max(right, last->second);

        ranges.erase(l, r);
        if (start < left) ranges[start] = left;
        if (end > right) ranges[right] = end;
    }

private:
    using IT = map<int, int>::iterator;
    map<int, int> ranges;

    void getOverlapRanges(int left, int right, IT& l, IT& r) {
        l = ranges.upper_bound(left);
        r = ranges.upper_bound(right);
        if (l != ranges.begin()) {
            if ((--l)->second < left) l++;
        }
    }


};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end
