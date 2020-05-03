// Given a collection of intervals, merge all overlapping intervals.
// 
// For example:
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].
// Make sure the returned intervals are sorted.


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a,Interval b) {
    if(a.start!=b.start) return (a.start> b.start) ? 0:1;
    else return (a.end>b.end) ? 0: 1;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
   sort(A.begin(),A.end(),compare);
   vector<Interval> res;
//   for(int i=0;i<A.size();i++) {
//       cout<<A[i].start <<" "<<A[i].end<<" ";
//   }
    int j=0;
    res.push_back(A[0]);
    for(int i=1;i<A.size();i++) {
        if(A[i].start<=res[j].end && A[i].start >= res[j].start) {
            if(A[i].end> res[j].end) {
                res[j].end=A[i].end;
            }
        }
        else {
            res.push_back(A[i]);
            j++;
        }
    }
   return res;
    
}
