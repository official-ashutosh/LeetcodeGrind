class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int, int> mp;
        while(n > 0){
            mp[n % 10]++;
            n /= 10;

        }

        int ans = 0;
        for(int i=1; i<10; i++) ans += (i*mp[i]);
        return ans;
    }
};