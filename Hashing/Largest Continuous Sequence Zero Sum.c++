// Find the largest continuous sequence in a array which sums to zero.
// Example:
// Input:  {1 ,2 ,-2 ,4 ,-4}
// Output: {2 ,-2 ,4 ,-4}
// 
// NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 
vector<int> Solution::lszero(vector<int> &A) {
    int sum=0;
    unordered_map<int,int> umap;
    umap[sum]=0;
    int len=0,p=-1,q=-1;
    vector<int> v;
    for(int i=0;i<A.size();i++) 
    {
        sum+=A[i];
        if(umap.find(sum)==umap.end()) umap[sum]=i+1;
        else {
            if(len<i+1-umap[sum]) {
                len=i+1-umap[sum];
                p=umap[sum];
                q=i+1;
            }
        }
    }
    for(int i=p;i<q;i++)
        v.push_back(A[i]);
    return v;
}

