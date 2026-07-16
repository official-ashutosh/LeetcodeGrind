class Solution {
public:

    
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ri(n, 1);

        stack<int> s;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] <= arr[i]) s.pop();

            if(!s.empty()) ri[i] = (s.top()-i);
            else ri[i] = (n-i); 

            s.push(i);
        }

        for(int i=0; i<n; i++){
            if(ri[i] == n-i) ri[i] = 0;
        }

        return ri;

    }
};