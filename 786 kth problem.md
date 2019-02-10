This post is a quick summary of all common solutions applicable to problems similar to *378. Kth Smallest Element in a Sorted Matrix* , where we are given an n x n matrix with each of the rows and columns sorted in ascending order, and need to find the kth smallest element in the matrix.

For your reference, the following is a list of LeetCode problems that can be transformed into problems equivalent to finding the “Kth Smallest Element in a Sorted Matrix” and thus can be solved effectively using the algorithms developed here:
1. 373. Find K Pairs with Smallest Sums
2. 378. Kth Smallest Element in a Sorted Matrix
3. 668. Kth Smallest Number in Multiplication Table
4. 719. Find K-th Smallest Pair Distance
5. 786. K-th Smallest Prime Fraction

## I-Shorting-based solution
This is the most straightforward solution, where we put all the elements in the matix into an array ans sort it in ascending order, then the **kth** smallest element in the matrix will be one at index **k - 1** of the array

```cpp
int kthSmallest(vector<vector<int>> matirx, int k){
    int n = matirx.size();
    vector<int> nums;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            nums.push_back(matrix[i][j]);
    sort(nums.begin(), nums.end());
    return nums[k - 1];
}
```
Time complexity: **O(n^2 * log(n^2))**
Space complexity: **O(n^2)**

## II-PriorityQueue-based solution
One observation here is that we don't need to keep track of all the **n^2** elements since only the **Kth** smallest element is required. We may maintain a **PriorityQueue** with size k to track only the **K** smallest in the matrix. At the end, the **kth** smallest element in the matrix will be the largest one in the **PriorityQueue**. Here is an implementation of this idea:

```cpp
int kthSmallest(vector<vector<int>> matrix, int k){
    priority_queue<int> pq;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            pq.push(matrix);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    return pq.top();
}
```

Time complexity: **O(n^2 * logk)**
Space complexity: **O(k)**

Though in the worst case **(k = n^2)**, the time and space complexities of this solution are the same as those of the naive solution above, we are still able to achieve slight performance gains for average cases where **k** is generally smaller compared to **n^2**.

## III-PriorityQueue-based solution with optimization

Up to this point, you may notice that the above two solutions actually apply to arbitrary matrices – they will find the kth smallest element in the matrix whether or not its rows or columns are sorted. What happens if we take advantage of the sorted properties of the matrix?

Well, I have yet to mention another straightforward way for finding the **kth** smallest element in the matrix: if we keep removing the smallest element from the matrix for **k-1** times, then after removing, the smallest element now in the matrix will be the **kth** smallest element we are looking for.

If the elements in the matrix are in random order, we have no better ways for finding and removing the smallest elements in the matrix other than adding all elements to a **PriorityQueue**. This will yield a time (and space) complexity no better, if not worse, than that of the naive solution. However, with the rows (or columns) of the matrix sorted, we don’t have to add all elements to the **PriorityQueue** at once. Instead, we can create a pool of candidate elements as long as we can ensure that it contains the smallest element of the matrix (even after removing).

Assume the rows are sorted in ascending order, which implies initially the smallest element of the matrix must be within the first column, therefore the pool can be initialized with elements from the first column. Now as we are extracting and removing smallest elements from the pool, we need to supplement more candiate elements. The key observation here is that for each extracted element, it suffices to add to the pool only the element immediately following it in the same row, without violating the property that the pool always contains the smallest element of the matrix (even after removing). The following is a solution based on this idea:

```cpp
int kthSmallest(vector<vector<int>> matrix, int k){
    auto cmp = [matrix](vector<int> &a, vector<int>& b){
        return matrix[a[0]][a[1]] > matrix[b[0]][b[1]];
    }; // 最小堆这样
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    int len = matirx.size();
    for(int i = 0 ; i < n; i++){
        pq.push({i, 0});  //initialize the pool with elements from the first column
    }
    while(--k > 0){ //remove the smallest elements from matrix (k - 1) times
        vector<int> p = pq.top(); pq.pop();
        if(++p[1] < len){
            pq.push(p); //add the next element in the same row if it exists
        }
    }
    return matrix[pq.top()[0]][pq.top()[1]];
}
```

Time complexity:**O(max(len, k) * logn)**
Space complexity:**O(len)**

Note that by making use of the sorted properties of the matrix, we were able to cut down the space complexity to **O(len)** and achieve a slightly better time complexity compared to that of the naive solution (though the worst case is the same).


## IV-BinarySearch-based solution
The binary search solution is essentially a special case of the more general “trial and error” algorithm described in my other post, where I have summarized the algorithm’s key ideas and demonstrated them for **LeetCode 719**. I would recommend you read at least the beginning part to get familiar with the terminologies that will be used here.

**The candidate solution:** in this case, the cadidate solution is simply an integer.

**The search space:** in this case, the search space is given by *[MIN, MAX]*, where MIN and MAX are the minimum and maximum elements in the matrix, respectively.

**The traverse method:** in this case, we can do a binary search since the search space is sorted naturally in ascending order (this also accounts for the name “BinarySearch-based solution”).

**The verification algorithm:** in this case, the verification algorithm is implemented by comparing the count of elements in the matrix less than or equal to the candidate solution, denoted as cnt, with the rank k: if cnt < k, we throw away the left half of the search space; otherwise we discard the right half.

Note that the verification algorithm is based on the following two observations:

1. There will be at least k elements in the matrix that are less than or equal to the kth smallest element.

2. If there are at least k elements in the matrix that are less than or equal to a candidate solution, then the actual kth smallest element in the matrix cannot be greater than this candiate solution.

Also the counting of elements no greater than a candidate solution can be done in linear time by employing the classic two-pointer techinique which takes advantage of the sorted properties of the matrix. The following is the solution for this algorithm:

```cpp
int kthSmallest(vector<vector<int>>& matrix, int k){
    int n = matrix.size();
    int l = matrix[0][0];
    int r = matrix[n - 1][n - 1];
    for(int cnt = 0; l < r; cnt = 0){
        int m = (l + r) / 2;
        // for(int i = n - 1, j = 0; i >= 0; i--){
        //     while(j < n && matrix[i][j] <= m) j++;
        //     cnt  += j;
        // }
        for(int i = 0, j = n - 1; i < n; i++){
            while(j >=0 && matrix[i][j] > m) j--;
            cnt += (j + 1);
        }
        if(cnt < k){
            l = m + 1;
        }else{
            r = m;
        }
    }
    return l;
}
```

**Time complexity:** O(n * log(MAX - MIN))
**Space complexity:** O(1)

The binary search solution is much more efficient compared to those derived in previous sections. We use only constant space and the time complexity is almost linear for any practical integer matrices (for which MIN and MAX are within the 32-bit integer range).


## V -- ZigzagSearch-based solution

The zigzag search solution is another special version of the more general **“trial and error”** algorithm, where now the search space is formed only by integers contained in the input matrix itself, rather than continous integers in the range [MIN, MAX]. We can summarize the following properties of this solution:

**The candidate solution:** in this case, the cadidate solution is also an integer, *but it must be an element of the input matrix.*

**The search space:** in this case, the search space is given by the input matrix itself.

**The traverse method:** in this case, we cannot do a binary search since there is no total ordering of the candidate solutions. However, we do have partial orderings where each row and column of the matrix are sorted in ascending order. This enables us to do a zigzag search where we start from the upper-right corner of the matrix and proceed to either the next row or previous column depending on the result of the verification algorithm (we can also start from the bottom-left corner and proceed to either the previous row or next column).

**The verification algorithm:** in this case, the verification algorithm is implemented by comparing two counts, denoted as **cnt_lt** and **cnt_le** respectively, with the rank **k: if cnt_le < k**, we proceed to the next row; else if **cnt_lt >= k**, we proceed to the previous column; otherwise we’ve found the kth smallest element in the matrix so return it. Here **cnt_lt denotes the number of elements in the matrix less than the candidate solution**, while **cnt_le denotes the number of elements in the matrix less than or equal to the candidate solution** (the reason we need two counts is that there may be duplicates in the input matrix).


Note that the verification algorithm is based on the following two observations:

1. There will be at most k - 1 elements in the matrix that are less than the kth smallest element.

2. There will be at least k elements in the matrix that are less than or equal to the kth smallest element.

And again the counting can be done in linear time using the classic two-pointer techinique. The following is the code for this algorithm:

```cpp
int kthSmallest(vector<vector<int>>& matrix, int k){
    int n = matrix.size();
    int row = 0;
    int col = n - 1;
    for(int cnt_le = 0, cnt_lt = 0; true; cnt_le = 0, cnt_lt = 0){
        for(int i = 0, j = n - 1, p = n - 1;i < n; i++){
            while(j >= 0 && matrix[i][j] > matrix[row][col]) j--;
            cnt_le += (j + 1);

            while(p >= 0 && matrix[i][j] >= matrix[row][col]) p--;
            cnt_lt += (p + 1);
        }
        if(cnt_le < k){
            row++;
        }else if(cnt_lt >= k){
            col--;
        }else{
            return matrix[row][col];
        }
    }
}
```

**Time complexity:** O(n^2)
**Space complexity:** O(1)

The zigzag search solution is less efficient compared to the binary search solution, but still achieves significant performance gains compared to the other three solutions.

## VI -- BiSelect solution

This is the most advanced algorithm for this type of problems that achieves linear time complexity. This BiSelect solution is good to know but may not be suitable for an interview, so you may opt to skip it and continue.

```java
public int kthSmallest(int[][] matrix, int k) {
    int n = matrix.length;

    int[] index = new int[n];

    for (int i = 0; i < n; i++) {
        index[i] = i;
    }

    int[] L = new int[12 * n];

    return biselect(matrix, index, k, k, L)[0];
}

private int[] biselect(int[][] matrix, int[] index, int k1, int k2, int[] L) {
    int n = index.length;

    if (n <= 2) {
        int[] nums = new int[n * n];

        for (int i = 0, k = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                nums[k++] = matrix[index[i]][index[j]];
            }
        }

        Arrays.sort(nums);

        return new int[] {nums[k1 - 1], nums[k2 - 1]};
    }

    int[] index_ = new int[(n + 1) / 2 + (n - 1) % 2];
    int k1_ = 0;
    int k2_ = (k2 + 3) / 4;

    for (int i = 0, k = 0; i < n; i += 2) {
        index_[k++] = index[i];
    }

    if (n % 2 == 0) {
        index_[index_.length - 1] = index[n - 1];
        k1_ = (k1 + 3) / 4 + n + 1;
    } else {
        k1_ = (k1 + 2 * n) / 4 + 1;
    }

    int[] pair = biselect(matrix, index_, k1_, k2_, L);
    int a = pair[0], b = pair[1];
    int ra_less = 0, rb_more = 0;

    int Len = 0;

    for (int i = 0, ja = n, jb = n; i < n; i++) {
        while (ja > 0 && matrix[index[i]][index[ja - 1]] >= a) ja--;
        ra_less += ja;

        while (jb > 0 && matrix[index[i]][index[jb - 1]] > b) jb--;
        rb_more += n - jb;

        for (int j = jb; j < ja; j++) {
            L[Len++] = matrix[index[i]][index[j]];
        }
    }

    int x = 0, y = 0;

    if (ra_less <= k1 - 1) {
        x = a;
    } else if (k1 + rb_more - n * n <= 0) {
        x = b;
    } else {
        x = L[pick(L, 0, Len, k1 + rb_more - n * n)];
    }

    if (ra_less <= k2 - 1) {
        y = a;
    } else if (k2 + rb_more - n * n <= 0) {
        y = b;
    } else {
        y = L[pick(L, 0, Len, k2 + rb_more - n * n)];
    }

    return new int[] {x, y};
}

private int pick(int[] nums, int l, int r, int k) {
    int[] pos = partition(nums, l, r, medianOfMedians(nums, l, r));

    int p = pos[0], q = pos[1];

    if (q - l < k) {
        return pick(nums, q, r, k - (q - l));
    } else if (k <= p - l) {
        return pick(nums, l, p, k);
    } else {
        return p;
    }
}

private int[] partition(int[] nums, int l, int r, int pos) {
    int pivot = nums[pos];
    swap(nums, pos, r - 1);

    int p = l, q = r - 1;

    for (int i = l; i < q;) {
        if (nums[i] < pivot) {
            swap(nums, p++, i++);
        } else if (nums[i] > pivot) {
            swap(nums, i, --q);
        } else {
            i++;
        }
    }

    swap(nums, q++, r - 1);

    return new int[] {p, q};
}

private int medianOfMedians(int[] nums, int l, int r) {
    if (r - l <= 5) return medianOfFive(nums, l, r);

    int rr = l;

    for (int i = l; i < r; i += 5) {
        swap(nums, rr++, medianOfFive(nums, i, Math.min(i + 5,  r)));
    }

    return pick(nums, l, rr, (rr - l + 1) / 2);
}

private int medianOfFive(int[] nums, int l, int r) {
    Arrays.sort(nums, l, r);
    return l + (r - l - 1) / 2;
}

private void swap(int[] nums, int i, int j) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}
```
**Time complexity:** O(n)
**Space complexiry:** O(n)

##VII -- Transform other problems into "Kth Smallest Element in a Sorted Matrix"

For problems other than the "Kth Smallest Element in a Sorted Matrix", to apply the algorithms developed above, we need to rephrase ans tranform them into one that is equivalent to finding the Kth Smallest Element in a Sorted Matrix.

Now the key to transformation process is to build the sored matrix in terms of the problem input. On the one hand, we need to relate each matrix element matrix[i][j] to the problem input ,on the other hand, we need to arrange these elements so that each row ans column of the matrix are sorted in ascending order. Again, these details will depend on the nature of the problems. But as far as this post is concerned, I will assume the input are two arrays sorted in ascending order, denoted as *a and b* respectively, and the matrix elements can be computed using arithmetic operations of the two array elements.

1. Addition: matrix[i][j] = a[i'] + b[j']
2. Substraction: matrix[i][j] = a[i'] - b[j']
3. Multiplication: matrix[i][j] = a[i'] * b[j']
4. Division: matirx[i][j] = a[i'] / b[j']

Note that the index mappings i --> i' and j --> j' are not necessarily identity mappings, but rahter they will be chosen to ensure that rows and columns in the matrix are sorted in ascending order. For simplicity, the two type of mappings are identity mapping (where i' = i and j' = j) and "negative" mapping (where i' = na - 1 - i and j' = nb - 1 - j)

Next I will reformulate LeetCode problems 378, 668, 719 and 786 as examples to show how the transormation is done:
- 373.Find K Pairs with smallest Sums: In this case, the two input arrays are nums1 and nums2, so a will refer to nums1 and b to nums2. And we have matrix[i][j] = nums1[i] + nums2[j], where identity mappings are chosen for both the row and column indices. Note that for this problem we are required to find all the K pairs with the smallest sums, so the optimized **PriorityQueue solution** would be the best to try.
- 668.Kth smallest Number in Multiplication Table: In this case, only the lengths of the two arrays are given as input, but it’s trival to get the array elements (a[i] = i + 1, b[j] = j + 1). And we have matrix[i][j] = a[i] * b[j], where again identity mappings are chosen for both the row and column indices. The Kth smallest element in the multiplication table will be the same as the Kth smallest element in the matrix.
- 719.Find K-th Smallest Pair Distance: In this case there is only one array nums as input, so both a and b will refer to nums. After sorting nums in ascending order, we have **matrix[i][j] = nums[i] - nums[n - 1 - j]**, where n = nums.length. Note that the mapping for column index is chosen to be “negative” in order to make sure the columns are sorted in ascending order. Also note that our matrix will contain all pair distances (including negative ones) while the original problem asks for the Kth smallest pair distance out of absolute pair distances (there are n(n-1)/2 such pairs). So we need to shift the rank up to **K' = K + n(n+1)/2**. The Kth smallest pair distance then will be the K'th smallest element in the matrix.
- 786.K-th Smallest Prime Fraction: In this case again there is only one array **A** as input, so both a and b will refer to **A**. We have matrix[i][j] = nums[i] / nums[n - 1 - j], where n = A.size() and / is floating point division(not integer division). Again the mappint for column index is chosen to be "negative" to ensure the columns are sorted in ascending order. The Kth smallest prime fraction then will be the Kth smallest element in the matrix.


## VIII -- Solutions for this problem (786. K-th Smallest Prime Fraction)

solution one: PriorityQueue with optimization
- Time complexity: O(max(n, K) * logn)
- Space complexity: O(n)

```cpp
vector<int> kthSmallestPrimeFraction(vector<int>& A, int K){
    int n = A.size();
    auto cmp = [&A, &n](pair<int, int>& a, pair<int, int>& b){
        return A[a.first] * A[n - 1 - b.second] > A[n - 1 - a.second] * A[b.first];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for(int i = 0; i < n; i++){
        pq.push(make_pair(i, 0));
    }
    while(--K){
        pair<int, int> p = pq.top(); pq.pop();
        if(++p.second < n){
            pq.push(p);
        }
    }
    return {A[pq.top().first], A[n - 1 - pq.top().second]};
}
```


solution two: Using BinarySearch
- Time complexity: O(n * log(MAX^2))
- Space complexity: O(1)

```cpp
vector<int> kthSmallestPrimeFraction(vector<int> A, int K){
    double l = 0, r = 1;
    int p = 0, q = 1;
    for(int n = A.size(), cnt = 0; true; cnt = 0, p = 0){
        double m = (l + r) / 2;
        for(int i = 0, j = n - 1; i < n; i++){
            while(j >= 0 && A[i] > m * A[n - 1 - j]) j--;
            cnt += (j + 1);
            if(j >= 0 && p * A[n - 1 - j] < q * A[i]){
                p = A[i];
                q = A[n - 1 - j];
            }
        }
        if(cnt < k){
            l = m;
        }else if(cnt > k){
            r = m;
        }else{
            return {p, q};
        }
    }
}
```

Remarks:
1. the kth smallest fraction is known to be in the range [0, 1], so we initialize the search space with this range(i.e, l = 0 and r = 1)
2. We need the pair (p, q) to record the maximum fraction in the matirx that is no greater than each candidate solution. This is necessary because on the one hand, the candidate solution itself cannot tell us what the numerator and denominator of the fraction are (remember the candidate solution is just a floating-point number);on the other hand, even if we can get the numerator and denominator of the candidate solution, these values may not be contained in the input array (remember all the fractions must be formed by pair of integers from the input array).This is different from the case when the matrix elements are integers, where at the end of the binary search, the candidate solution must be equal to the kth smallest element in the matrix.
3. The above solution only works when there are no duplicate fractions in the matrix (which is indeed the case for prime fractions). Otherwise, we need two counts, cnt_le and cnt_lt, to account for duplicates, similar to what we did in the ZigzagSearch solution below.
4. The time complexity is computed as follows: the binary search loop will terminate when the count of elements no greater than a candidate solution reaches K. This is guaranteed to happen when the size of the search range [l, r] becomes smaller than the smallest absolute distance between any pair of fractions in the matrix, which is >= 1/MAX^2. Since each iteration will reduce the search range by half, the binary search loop will terminate after at most log(MAX^2) steps. Each iteration is done in linear time, therefore the total time complexity is O(n * log(MAX^2)).

solution three: using zigzagsearch
- Time complexity: O(n^2)
- Space complexity: O(1)

```cpp
vector<int> kthSmallestPrimeFraction(vector<int> A, int K){
    int n = A.size();
    int row = 0;
    int col = n - 1;
    for(int cnt_le = 0, cnt_lt = 0; true; cnt_le = 0, cnt_lt = 0){
        for(int i = 0, j = n - 1, p = n - 1; i < n; i++){
            while(j >= 0 && A[i] * A[n - 1 - col] > A[n - 1 - j] * A[row]) j--;
            cnt_le += (j + 1);

            while(p >= 0 && A[i] * A[n - 1 - col] >= A[n - 1 - p] * A[row]]) p--;
            cnt_lt += (p + 1);
        }
        if(cnt_le < K){
            row++;
        }else if(cnt_lt >= K){
            col--;
        }else{
            return {A[row], A[n - 1 - col]};
        }
    }
}
```
