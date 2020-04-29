// Given a list of non negative integers, arrange them such that they form the largest number.
// 
// For example:
// 
// Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

 
int compare(string X, string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1: 0;
}
string Solution::largestNumber(const vector<int> &arr) {
    vector<string> v;
    string res="";
    int n=arr.size();
    for(int i=0;i<arr.size();i++)
        v.push_back(to_string(arr[i]));
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
        res+=v[i];
    int i=0;
    while(res[i]=='0')
        i++;
    if(i==res.length())
     res="0";
    return res;
}
