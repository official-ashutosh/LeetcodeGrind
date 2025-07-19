class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int l =  0, r = 1e9, ans = -1;

        while(l <= r){
            int mid = (l+r)/2;

            map<int, int> mp;
            for(auto i : houses) mp[i] = 0;
            for(auto i : heaters){
                mp[max(0,i-mid)]++;
                mp[i+mid+1]--;
            }

            int prev = 0;
            for(auto &i : mp){
                i.second += prev;
                prev = i.second;
            }

            int fl = 0;
            for(auto i : houses){
                if(!mp[i]){
                    fl = 1;
                    break;
                }
            }

            if(fl) l = mid+1;
            else {
                ans= mid;
                r = mid-1;
            }
        }

        return ans;
    }
};
