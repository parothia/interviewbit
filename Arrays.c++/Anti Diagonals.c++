// Give a N*N square matrix, return an array of its anti-diagonals.      Look at the example for more details.
// Example:
// Input: 	
// 1 2 3
// 4 5 6
// 7 8 9
// Return the following :
// 
// [ 
//   [1],
//   [2, 4],
//   [3, 5, 7],
//   [6, 8],
//   [9]
// ]


vector<vector<int> > Solution::diagonal(vector<vector<int> > &nums) {
    // vector<int> v;
    vector<vector<int>>res;
        int rows=nums.size();
        if(rows==0)
            return res;
        vector<int> s;
        int max=0;
        for(int i=0;i<rows;i++) {
            int temp=nums[i].size();
            if(max<temp)
                max=temp;
            s.push_back(temp);
        }
        int j=0;
        int i=0;
        int row=0;
        for(row=0;row<rows;row++) {
            j=0;
            i=row;
            vector<int> v;
            while(i>=0) {
                if(s[i]>j)
                v.push_back(nums[i][j]);
                i--;
                j++;
            }
            reverse(v.begin(),v.end());
            res.push_back(v);
        }
        return res;
}

