/*Given an index k, return the kth row of the Pascal’s triangle
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
Example:
Input : k = 3
Return : [1,3,3,1]
    NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
   */ 


vector<int> Solution::getRow(int n) {
    vector<int> save;
    for(int i=0;i<=n;i++) {
        vector<int> row;
        for(int j=0;j<=i;j++) {
            if(j==0 || j==i)
                row.push_back(1);
            else
                row.push_back(save[j-1]+save[j]);
        }
        save=row;
    }
    return save;
}

