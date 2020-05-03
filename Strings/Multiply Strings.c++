// Given two numbers represented as strings, return multiplication of the numbers as a string.
// 
//     Note: The numbers can be arbitrarily large and are non-negative.
//     Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer. 
// 
// For example,
// given strings "12", "10", your answer should be “120”.
// 
// NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ).  


void sumkro(vector<int> &res,vector<int> &temp) {
    int a=res.size();
    int b=temp.size();
    int c=0;
    int sum=0;
    int i=0,j=0;
    while(i<a || j<b) {
        sum=0;
        if(i<a) sum+=res[i];
        if(j<b) sum+=temp[j];
        sum+=c;
        c=0;
        if(sum>9) {
            c=sum/10;
            sum=sum%10;
        }
        if(i==a) res.push_back(sum);
        else res[i++]=sum;
        j++;
    }
    if(c) res.push_back(1);
    
}
string Solution::multiply(string A, string B) {
    string r="";
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int a=A.length();
    int b=B.length();
    if(!a) return B;
    if(!b) return A;
    vector<int> AA,BB;
    for(int i=0;i<a;i++) {
        AA.push_back(A[i]-'0');
    }
    for(int i=0;i<b;i++) {
        BB.push_back(B[i]-'0');
    }
    vector<int> res;
    for(int i=0;i<b;i++) {
        vector<int> temp;
        int t=i;
        while(t--) {
            temp.push_back(0);
        }
        int carry=0;
        int sum=0;
        for(int j=0;j<a;j++) {
            sum=BB[i]*AA[j]+carry;
            carry=0;
            if(sum>9) {
                carry=sum/10;
                sum=sum%10;
            }
            temp.push_back(sum);
        }
        if(carry) temp.push_back(carry);
        if(i==0) {
            res=temp;
        }
        else sumkro(res,temp);
        
    }
    int i=res.size()-1;
    while(res[i]==0)
        i--;
    if(i<0) {
        r="0";
        return r;
    }
    for(;i>=0;i--) {
        r.push_back(res[i]+'0');
    }
    return r;
}
