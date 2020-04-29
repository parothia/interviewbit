// Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.
// Input 1:
//     A = 3
// 
// Output 1:
//     [   [ 1, 2, 3 ],
//         [ 8, 9, 4 ],
//         [ 7, 6, 5 ]   ]


vector<vector<int> > Solution::generateMatrix(int n) {
    vector<vector<int>> v;
    vector<int> row;
    for(int i=0;i<n;i++)
        row.push_back(i);
    for(int i=0;i<n;i++)
        v.push_back(row);
    int left=0,up=0;
    int down=n-1,right=n-1;
    
    int el=1;
    while(left<=right && up<=down) {
        for(int i=left;i<=right;i++)
            v[up][i]=el++;
        up++;
        for(int i=up;i<=down;i++)
            v[i][right]=el++;
        right--;
        
        if(up<=down) {
            for(int i=right;i>=left;i--)
                v[down][i]=el++;
            down--;
        }
        if(left<=right) {
            for(int i=down;i>=up;i--)
                v[i][left]=el++;
            left++;
        }
    }
    return v;
}

