/*
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix
 *
 * Medium (44.43%)
 * Total Accepted:
 * Total Submissions:
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 *
 *
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 *
 *
 * Example:
 *
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 *
 * return 13.
 *
 *
 *
 * Note:
 * You may assume k is always valid, 1 ? k ? n2.
 */
class Solution {
public:
    // // klog(n) priority queue solution
    // struct compare
    // {
    //     bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b)
    //     {
    //         return a.first>b.first;
    //     }
    // };
    // int kthSmallest(vector<vector<int>>& arr, int k) {
    //
    //     int n=arr.size(),m=arr[0].size();
    //
    //     priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, compare > p;
    //
    //     for(int i=0;i<n;i++)
    //     p.push(make_pair(arr[i][0],make_pair(i,0)));
    //
    //     int x=k,ans;
    //     while(x--)
    //     {
    //         int e=p.top().first;
    //         int i=p.top().second.first;
    //         int j=p.top().second.second;
    //         ans=e;
    //         p.pop();
    //         if(j!=m-1)
    //         p.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
    //     }
    //     return ans;
    //
    // }

    int kthSmallest(vector<vector<int>>& matrix, int k){
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        int mid = 0;
        while(l < r){
            mid = l + (r - l) / 2;
            int num = 0; // number of elements no bigger than mid
            for(int i = 0; i < n; i++){
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            if(num < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }

    // //BS solution
    // int kthSmallest(vector<vector<int>>& matrix, int k)
	// {
	// 	int n = matrix.size();
	// 	int le = matrix[0][0], ri = matrix[n - 1][n - 1];
	// 	int mid = 0;
	// 	while (le < ri)
	// 	{
	// 		mid = le + (ri-le)/2;
	// 		int num = 0; // number of elements no bigger than mid
	// 		for (int i = 0; i < n; i++)
	// 		{
	// 			int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
	// 			num += pos;
	// 		}
	// 		if (num < k)
	// 		{
	// 			le = mid + 1;
	// 		}
	// 		else
	// 		{
	// 			ri = mid;
	// 		}
	// 	}
	// 	return le;
	// }
};
