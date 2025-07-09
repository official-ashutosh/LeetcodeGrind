class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 1, 0);
        
        gaps[0] = startTime[0]; 
        for(int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i - 1];  
        }
        gaps[n] = eventTime - endTime[n - 1];  

        int mx = 0;
        vector<int> pre(n + 1, 0);
        pre[0] = gaps[0];
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + gaps[i];  
        }

        int l = 0, r = 0;
        while(r <= n) {  
            if(r - l > k) {
                l++; 
            }

            int k = pre[r];
            if(l > 0) k -= pre[l-1];
            mx = max(mx, k);  
            r++;  
        }

        return mx;
    }
};
