class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ct = 0;
        sort(intervals.begin(),intervals.end());

        int lst = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] < lst){
                ct++;
                lst = min(lst,intervals[i][1]);
            }
            else{
                lst = intervals[i][1];
            }
        }
        return ct;
    }
};