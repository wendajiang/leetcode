# Permutations
Given a collection of numbers, return all possible permutaions

## Recursive Solution:
Basic idea: permutation of A[1...n] equals to
A[1] + permutaiton of (A[1...n] - A[1])
A[2] + permutaiton of (A[1...n] - A[2])
...
A[n] + permutaiton of (A[1...n] - A[n])

```cpp
class Solution{
public:
    vector<vector<int>> permute(vector<int> &num){
        vector<vector<int>> res;
        permutationRecursive(num, 0, res);
        return res;
    }
    void permutationRecursive(vector<int>& num, int begin, vector<vector<int>>& res){
        if(begin >= num.size()){
            res.push_back(num);
            return;
        }
        for(int i = begin; i < num.size(); i++){
            swap(num[begin], num[i]);
            permutationRecursive(num, begin + 1, res);
            swap(num[begin], num[i]);
        }
    }
}
```
