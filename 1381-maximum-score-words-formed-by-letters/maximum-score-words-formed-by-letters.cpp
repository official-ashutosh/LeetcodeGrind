class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();

        map<char, int> mp;
        for(auto i : letters) mp[i]++;

        int m = (1<<n)-1;
        int ans = 0;
        for(int i=m; i>=0; i--){
            map<char, int> mp2;
            int ans2 = 0;
            for(int j=0; j<n; j++){
                if(i & (1<<j)){
                    for(auto c : words[j]){
                        mp2[c]++;
                        if(mp2[c] > mp[c]) {
                            ans2 = INT_MAX;
                            break;
                        }
                        ans2 += score[c-'a'];
                    }
                }

                if(ans2 == INT_MAX) break;
            }
            if(ans2 != INT_MAX)
            ans = max(ans, ans2);
        }

        return ans;
    }
};