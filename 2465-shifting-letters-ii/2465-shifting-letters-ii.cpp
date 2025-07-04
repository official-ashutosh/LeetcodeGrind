class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<long long> v(n+1,0);

        for(auto i : shifts){
            if(i[2] == 0){
                v[i[0]]--;
                v[i[1]+1]++;
            } else {
                v[i[0]]++;
                v[i[1]+1]--;
            }
        }

        for(int i=1; i<n; i++){
            v[i] += v[i-1];
        }


        for(int i=0; i<n; i++){
            int p = (v[i]%26+26) % 26;
            s[i] += p;
            if(s[i] >= 'a' && s[i] <= 'z') continue;

            s[i] -= 26;
        }

        return s;


    }
};