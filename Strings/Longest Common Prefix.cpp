// Given the array of strings A,
// you need to find the longest string S which is the prefix of ALL the strings in the array.
// 
// Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
// and S2.
// 
// For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
// Input 1:
//     A = ["abcdefgh", "aefghijk", "abcefgh"]
// Output 1:
//     "a"
//     Explanation 1:
//         Longest common prefix of all the strings is "a".



    #include<bits/stdc++.h>
    string Solution::longestCommonPrefix(vector<string> &A) {
        int n=A.size();
        // cout<<A[0].size();
        int min=A[0].size();
        int i=0;
        for(i=1;i<n;i++) {
            if(min>A[i].size())
                min=A[i].size();
        }
        // cout<<min;
        for(i=0;i<min;i++) {
            int flag=0;
            for(int j=1;j<n;j++) {
                if(A[0][i]==A[j][i]) {
                    // cout<<A[j][i]<<" ";
                    continue;
                }
                flag=1;
                break;
            }
            // cout<<flag;
            if(flag==1)
                break;
        }
        return A[0].substr(0,i);
        string str;
        return str;
    }

