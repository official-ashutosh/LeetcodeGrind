class Solution {
public:
    int dp[100001];
    const int mod=1e9+7;
    int rec(int i,string &s,vector<int>&mp){
        if(i>=s.size()){
            return 1;
        }
        int ans=0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxx=mp[s[i]-'0'];
        for(int j=i;j<i+maxx;j++){
            if(s[i]!=s[j]){
                break;
            }
            ans=(ans+(rec(j+1,s,mp)))%mod;
        }
        return dp[i]=ans;
    }
    int countTexts(string pressedKeys) {
        vector<int>mp(10,3);
        mp[7]++;mp[9]++;
        memset(dp,-1,sizeof(dp));
        return rec(0,pressedKeys,mp);
    }
}; 