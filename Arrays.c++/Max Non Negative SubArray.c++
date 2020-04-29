// Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.
// The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
// Maximum sub-array is defined in terms of the sum of the elements in the sub-array.
// Find and return the required subarray.
// Input 1:
//     A = [1, 2, 5, -7, 2, 3]
// Output 1:
//     [1, 2, 5]
// Explanation 1:
//     The two sub-arrays are [1, 2, 5] [2, 3].
//     The answer is [1, 2, 5] as its sum is larger than [2, 3].
// Input 2:
//     A = [10, -1, 2, 3, -4, 100]
// Output 2:
//     [100]
// Explanation 2:
//     The three sub-arrays are [10], [2, 3], [100].
//     The answer is [100] as its sum is larger than the other two.


vector<int> Solution::maxset(vector<int> &A) {
    int l=0,r=0;
    int p=0,q=0;
    long long int sum=0,psum=-1;
    int n=A.size();
    int i=0;
    while(i<A.size()) {
        
        if(A[i]>=0) {
            sum+=A[i];
            r++;
        }
        else {
            l=i+1;
            r=i+1;
            sum=0;
        }
        if(sum>=psum ) {
            if((q-p<r-l)|| psum<sum)
            {
                p=l;
                q=r;
            }
            psum=sum;
        }
        i++;
    }
    vector<int> v;
        for(int j=p;j<q;j++) {
            v.push_back(A[j]);
        }
    return v;
}

