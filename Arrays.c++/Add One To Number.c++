// Given a non-negative number represented as an array of digits,
// add 1 to the number ( increment the number represented by the digits ).
// The digits are stored such that the most significant digit is at the head of the list.
// Example:
// If the vector has [1, 2, 3]
// the returned vector should be [1, 2, 4]
// as 123 + 1 = 124.

vector<int> Solution::plusOne(vector<int> &digits) {
    int carry=1;
        int sum=0;
        int n=digits.size()-1;
        int flag=1;
        int j=0;
        int l=-1;
            while(digits[l+1]==0) {
                l++;
            }
        int k=0;
        if(l>=0)
            l+=1;
        j=l;
        // cout<<j<<" GGGG";
        if(j==n+1)
            j--;
        if(j>=0) {
            // cout<<"FF";
            while(j<=n) {
                swap(digits[k],digits[j]);
                k++;j++;
            }
            j--;k--;
            while(j>k) {
                digits.pop_back();
                n--;
                j--;
            }
        }
        for(int i=n;i>=1;i--) {
            sum=digits[i]+carry;
            if(sum>9) {
                digits[i]=0;
                carry=1;
            }
            else {
                digits[i]=sum;
                carry=0;
            }
        }
        if(digits[0]>8 && carry) {
            digits.push_back(1);
            digits[0]=0;
            for(int i=n+1;i>0;i--)
                swap(digits[i],digits[i-1]);
        }
        else {
            digits[0]=digits[0]+carry;
        }
        return digits;
}
