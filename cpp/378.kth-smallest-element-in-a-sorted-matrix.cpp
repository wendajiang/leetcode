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

    // int kthSmallest(vector<vector<int>>& matrix, int k){
    //     int len = matrix.size();
    //     auto cmp = [&matrix](pair<int, int>& a, pair<int, int>& b){
    //         return matrix[a.first][a.second] > matrix[b.first][b.second];
    //     };
    //     priority_queue<pair<int, int>, vector<pair<int, int>> , decltype(cmp)> pq(cmp);
    //
    //     for(int i = 0 ; i < len; i++){
    //         pq.push({i, 0});
    //     }
    //     while(--k){
    //         pair<int, int> p = pq.top(); pq.pop();
    //         if(++p.second < len){
    //             pq.push(p);
    //         }
    //     }
    //     return matrix[pq.top().first][pq.top().second];
    // }

    // //BS solution
    // int kthSmallest(vector<vector<int>>& matrix, int k){
    //     int n = matrix.size();
    //     int l = matrix[0][0];
    //     int r = matrix[n - 1][n - 1];
    //     for(int cnt = 0; l < r; cnt = 0){
    //         int m = (l + r) / 2;
    //         for(int i = n - 1, j = 0; i >= 0; i--){
    //             while(j < n && matrix[i][j] <= m) j++;
    //             cnt += j;
    //         }
    //         if(cnt < k){
    //             l = m + 1;
    //         }else{
    //             r = m;
    //         }
    //     }
    //     return l;
    // }

    // Time O(n) Space O(n)
    int kthSmallest(const std::vector<std::vector<int>> & matrix, int k)
	{
		if (k == 1) // guard for 1x1 matrix
		{
			return matrix.front().front();
		}

		size_t n = matrix.size();
		std::vector<size_t> indices(n);
		std::iota(indices.begin(), indices.end(), 0);
		std::array<size_t, 2> ks = { k - 1, k - 1 }; // use zero-based indices
		std::array<int, 2> results = biSelect(matrix, indices, ks);
		return results[0];
	}

private:
	// select two elements from four elements, recursively
	std::array<int, 2> biSelect(
		const std::vector<std::vector<int>> & matrix,
		const std::vector<size_t> & indices,
		const std::array<size_t, 2> & ks)
	// Select both ks[0]-th element and ks[1]-th element in the matrix,
	// where k0 = ks[0] and k1 = ks[1] and n = indices.size() satisfie
	// 0 <= k0 <= k1 < n*n  and  k1 - k0 <= 4n-4 = O(n)   and  n>=2
	{
		size_t n = indices.size();
		if (n == 2u) // base case of resursion
		{
			return biSelectNative(matrix, indices, ks);
		}

		// update indices
		std::vector<size_t> indices_;
		for (size_t idx = 0; idx < n; idx += 2)
		{
			indices_.push_back(indices[idx]);
		}
		if (n % 2 == 0) // ensure the last indice is included
		{
			indices_.push_back(indices.back());
		}

		// update ks
		// the new interval [xs_[0], xs_[1]] should contain [xs[0], xs[1]]
		// but the length of the new interval should be as small as possible
		// therefore, ks_[0] is the largest possible index to ensure xs_[0] <= xs[0]
		// ks_[1] is the smallest possible index to ensure xs_[1] >= xs[1]
		std::array<size_t, 2> ks_ = { ks[0] / 4, 0 };
		if (n % 2 == 0) // even
		{
			ks_[1] = ks[1] / 4 + n + 1;
		}
		else // odd
		{
			ks_[1] = (ks[1] + 2 * n + 1) / 4;
		}

		// call recursively
		std::array<int, 2> xs_ = biSelect(matrix, indices_, ks_);

		// Now we partipate all elements into three parts:
		// Part 1: {e : e < xs_[0]}.  For this part, we only record its cardinality
		// Part 2: {e : xs_[0] <= e < xs_[1]}. We store the set elementsBetween
		// Part 3: {e : x >= xs_[1]}. No use. Discard.
		std::array<int, 2> numbersOfElementsLessThanX = { 0, 0 };
		std::vector<int> elementsBetween; // [xs_[0], xs_[1])

		std::array<size_t, 2> cols = { n, n }; // column index such that elem >= x
		 // the first column where matrix(r, c) > b
		 // the first column where matrix(r, c) >= a
		for (size_t row = 0; row < n; ++row)
		{
			size_t row_indice = indices[row];
			for (size_t idx : {0, 1})
			{
				while ((cols[idx] > 0)
					&& (matrix[row_indice][indices[cols[idx] - 1]] >= xs_[idx]))
				{
					--cols[idx];
				}
				numbersOfElementsLessThanX[idx] += cols[idx];
			}
			for (size_t col = cols[0]; col < cols[1]; ++col)
			{
				elementsBetween.push_back(matrix[row_indice][indices[col]]);
			}
		}

		std::array<int, 2> xs; // the return value
		for (size_t idx : {0, 1})
		{
			size_t k = ks[idx];
			if (k < numbersOfElementsLessThanX[0]) // in the Part 1
			{
				xs[idx] = xs_[0];
			}
			else if (k < numbersOfElementsLessThanX[1]) // in the Part 2
			{
				size_t offset = k - numbersOfElementsLessThanX[0];
				std::vector<int>::iterator nth = std::next(elementsBetween.begin(), offset);
				std::nth_element(elementsBetween.begin(), nth, elementsBetween.end());
				xs[idx] = (*nth);
			}
			else // in the Part 3
			{
				xs[idx] = xs_[1];
			}
		}
		return xs;
	}

	// select two elements from four elements, using native way
	std::array<int, 2> biSelectNative(
		const std::vector<std::vector<int>> & matrix,
		const std::vector<size_t> & indices,
		const std::array<size_t, 2> & ks)
	{
		std::vector<int> allElements;
		for (size_t r : indices)
		{
			for (size_t c : indices)
			{
				allElements.push_back(matrix[r][c]);
			}
		}
		std::sort(allElements.begin(), allElements.end());
		std::array<int, 2> results;
		for (size_t idx : {0, 1})
		{
			results[idx] = allElements[ks[idx]];
		}
		return results;
	}


};
