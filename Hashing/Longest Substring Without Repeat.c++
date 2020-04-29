// Given a string,
// find the length of the longest substring without repeating characters.
// 
// Example:
// 
// The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
// 
// For "bbbbb" the longest substring is "b", with the length of 1

int Solution::lengthOfLongestSubstring(string str) {
    int n=str.length();
    int len=0;
    int i=0,j=0;
    // if(n==0||n==1 ) return n;
    unordered_map<char,int> umap;
    while(j<n) {
        while(j<n && umap.find(str[j])==umap.end()) {
            umap[str[j]]=1;
            j++;
        }
        
        if(len<j-i)
            len=j-i;
        umap.erase(str[i]);
        i++;
        
    }
    return len;
}

