// You are in an infinite 2D grid where you can move in any of the 8 directions :
//  (x,y) to 
//     (x+1, y), 
//     (x - 1, y), 
//     (x, y+1), 
//     (x, y-1), 
//     (x-1, y-1), 
//     (x+1,y+1), 
//     (x-1,y+1), 
//     (x+1,y-1) 
// You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.
// Input : [(0, 0), (1, 1), (1, 2)]
// Output : 2


int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int sum=0;
    int j;
    for(int i=1,j=1;i<A.size();i++,j++) {
        sum+=max(abs(A[i]-A[i-1]),abs(B[i]-B[i-1]));
    }
    return sum;
}
