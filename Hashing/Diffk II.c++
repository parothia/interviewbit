// Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
// Example :
// Input :
// A : [1 5 3]
// k : 2
// Output :
// 1
// as 3 - 1 = 2
// Return 0 / 1 for this problem.



int Solution::diffPossible(const vector<int> &A, int k) {
    unordered_map<int,int> umap;
    int n=A.size();
    if(n<2) return 0;
    for(int i=0;i<n;i++){
        umap[A[i]]++;
    }
    for(int i=0;i<n;i++) 
    {
        if(k==0) {
            if(umap.find(k+A[i])==umap.end())
                return 0;
            if(umap[k+A[i]]>=2)
                return 1;
            return 0;
        }
        if(umap.find(k+A[i])==umap.end())
            continue;
        return 1;
    }
    return 0;
}

