// MAINNNNNNNNNNNNN
//  input   1, 2, 3, 5, 7, 6, 4
//  output     1 2 3 6 4 5 7 
// Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.
// 
// If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order. 
// Input 1:
//     A = [1, 2, 3]
// 
// Output 1:
//     [1, 3, 2]
//     
//     
//     
    
vector<int> Solution::nextPermutation(vector<int> &v) {
     int n = v.size();
        int ind = -1;
        for(int i=n-2;i>=0;--i) {
            if(v[i]<v[i+1]) {
                ind=i;
                break;
            }
        }
        // cout<<ind<<"       ";
        if(ind!=-1) {
            int ind2=ind+1;
            for(int i=ind+1;i<n;++i) {
                if(v[i]>v[ind]) {
                    ind2=i;
                }
            }
            swap(v[ind],v[ind2]);
        }
        sort(v.begin()+ind+1,v.end());
        return v;
}
