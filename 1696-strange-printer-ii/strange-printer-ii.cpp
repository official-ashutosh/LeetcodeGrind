class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {

        int n = targetGrid.size();
        int m = targetGrid[0].size();

        vector<vector<int>> v(61, vector<int>(4));

        for(int col=1; col<61; col++) {
            v[col][0] = INT_MAX;
            v[col][1] = INT_MAX;
            v[col][2] = INT_MIN;
            v[col][3] = INT_MIN;
        }

        set<int> s;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                int col = targetGrid[i][j];
                s.insert(col);

                v[col][0] = min(v[col][0], i);
                v[col][1] = min(v[col][1], j);
                v[col][2] = max(v[col][2], i);
                v[col][3] = max(v[col][3], j);
            }
        }

        vector<vector<int>> graph(61);
        vector<int> indegree(61, 0);

        for(auto col : s){

            int r1 = v[col][0];
            int c1 = v[col][1];
            int r2 = v[col][2];
            int c2 = v[col][3];

            set<int> seen;

            for(int i=r1; i<=r2; i++){
                for(int j=c1; j<=c2; j++){

                    int cr = targetGrid[i][j];

                    if(cr != col && !seen.count(cr)){

                        graph[cr].push_back(col);
                        indegree[col]++;

                        seen.insert(cr);
                    }
                }
            }
        }

        queue<int> q;

        for(auto col : s){
            if(indegree[col] == 0)
                q.push(col);
        }

        int done = 0;

        while(!q.empty()){

            auto col = q.front();
            q.pop();

            done++;

            for(auto next : graph[col]){

                indegree[next]--;

                if(indegree[next] == 0)
                    q.push(next);
            }
        }

        return done == s.size();
    }
};