// For Given Number N find if its COLORFUL number or not
// Return 0/1
// 
// COLORFUL number:
// A number can be broken into different contiguous sub-subsequence parts. 
// Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
// And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
// 
// Example:
// N = 23
// 2 3 23
// 2 -> 2
// 3 -> 3
// 23 -> 6
// this number is a COLORFUL number since product of every digit of a sub-sequence are different. 
// Output : 1



int Solution::colorful(int A) {
    int n=A;
    vector<int> nums;
    while(n) {
        nums.push_back(n%10);
        n=n/10;
    }
    reverse(nums.begin(),nums.end());
    unordered_map<int,int> umap;
    n=nums.size();
    for (int i=0;i<n;i++) { 
        for (int j=i;j<n;j++) {
            int mul=1;
            for (int k=i; k<=j; k++) 
                mul=mul*nums[k];
            if(umap.find(mul)!=umap.end()) return 0;
            umap[mul]++;
        } 
    } 
    return 1;
}
