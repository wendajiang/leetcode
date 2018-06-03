## First Attempt
The initial thought is straightforward, try every possible removal and recursively search the rest. No doubt it will be a TLE answer. Obviously there are a lot of recomputations involved here. Memoization is the key then. But how to design the memory is tricky. I tried to use a string of 0s and 1s to indicate whether the box is removed or not, but still getting TLE.

## One step further
I think the problem of the approach above is that there are a lot of unnecessary computations (not recomputations). For example, if there is a formation of ABCDAA, we know the optimal way is B->C->D->AAA. On the other hand, if the formation is BCDAA, meaning that we couldn't find an A before D, we will simply remove AA, which will be the optimal solution for removing them. Note this is true only if AA is at the end of the array. With naive memoization approach, the program will search a lot of unnecessary paths, such as C->B->D->AA, D->B->C->AA.

Therefore, I designed the memoization matrix to be memo[l][r][k], the largest number we can get using lth to rth
(inclusive) boxes with k same colored boxes as rth box appended at the end. Example, memo[l][r][3] represents the solution for this setting: [b_l, ..., b_r, A,A,A] with b_r==A.

The transition function is to find the maximum among all b_i==b_r for i=l,...,r-1:

memo[l][r][k] = max(memo[l][r][k], memo[l][i][k+1] + memo[i+1][r-1][0])

Basically, if there is one i such that b_i==b_r, we partition the array into two: [b_l, ..., b_i, b_r, A, ..., A], and [b_{i+1}, ..., b_{r-1}]. The solution for first one will be memo[l][i][k+1], and the second will be memo[i+1][r-1][0]. Otherwise, we just remove the last k+1 boxes (including b_r) and search the best solution for lth to r-1th boxes. (One optimization here: make r as left as possible, this improved the running time from 250ms to 35ms)

The final solution is stored in memo[0][n-1][0] for sure.

I didn't think about this question for a long time in the contest because the time is up. There will be a lot of room for time and space optimization as well. Thus, if you find any flaws or any improvements, please correct me.
