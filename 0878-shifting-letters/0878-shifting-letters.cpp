class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();

        vector<long long> v(n);
        v[n-1] = shifts[n-1];
        for(int i=n-2; i>=0; i--){
            v[i] += v[i+1] + shifts[i];
        }

        for(int i=0; i<n; i++){
            int p = v[i] % 26;
            s[i] += p;
            if(s[i] >= 'a' && s[i] <= 'z') continue;

            s[i] -= 26;
        }

        return s;
    }
};