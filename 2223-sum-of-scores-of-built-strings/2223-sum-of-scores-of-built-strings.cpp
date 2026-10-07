class Solution {
public:

    vector<int> zFunc(string &s){
        int n = s.size();
        vector<int> z(n);

        z[0] = n;

        int left = 0, right = 0;
        for(int i=1; i<n; i++){
            if(right >= i){
                z[i] = min(right-i+1, z[i-left]);
            }

            while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
                z[i]++;
            }

            if(i + z[i]-1 > right){
                left = i;
                right = i + z[i]-1;
            }
        }

        return z;
    }

    long long sumScores(string s) {
        int n = s.size();
        vector<int> z = zFunc(s);
        long long ans = 0;

        for(int i=0; i<n; i++){
            ans += z[i];
        }

        return ans;
    }
};