class Solution {
public:

    static bool mycomp( vector<int>&a,  vector<int>&b){
        return (a[1]-a[0]) < (b[1]-b[0]);
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), mycomp);

        int ans = 0;
        for(auto i : tasks){
            ans = max(ans+i[0], i[1]);
        }

        return ans;
    }
};