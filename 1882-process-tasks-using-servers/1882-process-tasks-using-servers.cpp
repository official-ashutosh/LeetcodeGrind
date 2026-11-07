class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> idle;

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > busy;

        int n = servers.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            idle.push({servers[i], i});
        }

        long long time = 0;

        for(int i=0; i<tasks.size(); i++) {
            time = max(time, (long long)i);

            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t, w, idx] = busy.top();
                busy.pop();
                idle.push({w, idx});
            }

            if(idle.empty()) {
                time = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [t, w, idx] = busy.top();
                    busy.pop();
                    idle.push({w, idx});
                }
            }

            auto [w, idx] = idle.top();
            idle.pop();

            ans.push_back(idx);
            busy.push({time + tasks[i], w, idx});
        }

        return ans;
    }
};