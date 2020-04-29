// Find the contiguous subarray within an array, A of length N which has the largest sum.
// Input 1:
//     A = [1, 2, 3, 4, -10]
// 
// Output 1:
//     10
// 
// Explanation 1:
//     The subarray [1, 2, 3, 4] has the maximum possible sum of 10.


int Solution::maxSubArray(const vector<int> &arr) {
    int sum=0;
    int n=arr.size();
    if(n==1)
        return arr[0];
    int maxsum=arr[0];
    for(int i=0;i<n;i++) {
        sum+=arr[i];
        if(sum>maxsum) {
            maxsum=sum;
        }
        if(sum<0) {
            sum=0;
            continue;
        }
    }
    return maxsum;
}
