class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map<int, int> mp;

        vector<long long> v(n,0);

        sort(meetings.begin(), meetings.end());

        for(auto i : meetings){
            long long st = i[0];
            long long en = i[1];

            int fl =0;
            for(int j=0; j<n;j++){
                if(v[j] <= st){
                    fl = 1;
                    v[j] = en;

                    mp[j]++;

                    break;
                }
            }

            if(!fl){
                long long mn = LLONG_MAX, id = -1;
                for(int j=0;j<n; j++){
                    if(mn > v[j]){
                        mn = v[j];
                        id = j;
                    }
                }

                mp[id]++;

                v[id] += (en-st);
            }

        }


        int ans = -1, mx = -1;
        for(auto i : mp){
            if(mx < i.second){
                ans = i.first;
                mx = i.second;
            }
        }

        return ans;
    }
};
