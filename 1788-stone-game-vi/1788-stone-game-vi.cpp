class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<pair<int, int>> v;

        int n = a.size();
        for(int i=0; i<n; i++){
            v.push_back({a[i]+b[i], i});
        }

        sort(v.begin(), v.end());

        for(auto i : v){
            cout << i.second << endl;
        }

        int sm1 = 0, sm2 = 0, l = 0, r = n-1, f = 0;

        while(l <= r){
            if(f){
                sm2 += b[v[r].second];
                r--;

                f = 0;
            } else {
                sm1 += a[v[r].second];
                r--;

                f = 1;
            }
        }

        cout << sm1 << " " << sm2 << endl;

        if(sm1 > sm2) return 1;
        else if(sm1 < sm2) return -1;
        return 0;
    }
};