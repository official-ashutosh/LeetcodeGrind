class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;

        map<int, int> mp;
        for(auto x : hand) mp[x]++;

        for(auto [x, cnt] : mp){
            if(cnt == 0) continue;

            for(int i=0; i<groupSize; i++){
                if(mp[x+i] < cnt) return false;
                mp[x+i] -= cnt;
            }
        }

        return true;
    }
};