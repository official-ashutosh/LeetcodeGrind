class Solution {
public:
    int minMoves(vector<string>& c, int energy) {
        int n = c.size();
        int m = c[0].size();

        pair<int, int> st;
        vector<pair<int, int>> v, re;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(c[i][j] == 'S') st = {i, j};
                if(c[i][j] == 'L') v.push_back({i, j});
            }
        }

        int L = v.size();
        int ff = (1 << L) - 1;

        queue<tuple<int, int, int, int, int>> q;
        int si = st.first, sj = st.second;
        int iM = 0;
        q.emplace(si, sj, energy, iM, 0);

        static bool vis4D[20][20][51][1<<10];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int e=0; e<=energy; e++){
                    for(int mk=0; mk<=ff; mk++){
                        vis4D[i][j][e][mk] = false;
                    }
                }
            }
        }
        vis4D[si][sj][energy][iM] = true;

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!q.empty()){
            auto [i, j, rm, mpp, f] = q.front();
            q.pop();

            if(mpp == ff){
                return f;
            }
            if(rm == 0 && c[i][j] != 'R') continue;

            for(auto k : dir){
                int x = i + k.first;
                int y = j + k.second;

                if(x < n && y < m && x >= 0 && y >= 0 && c[x][y] != 'X'){
                    int nE = -1;
                    if(c[x][y] == 'R'){
                        nE = energy;
                    } else if(rm > 0){
                        nE = rm - 1;
                    }
                    if(nE < 0) continue;

                    int nM = mpp;
                    if(c[x][y] == 'L'){
                        for(int idx = 0; idx < L; idx++){
                            if(v[idx].first == x && v[idx].second == y){
                                nM = mpp | (1 << idx);
                                break;
                            }
                        }
                    }

                    if(!vis4D[x][y][nE][nM]){
                        vis4D[x][y][nE][nM] = true;
                        q.emplace(x, y, nE, nM, f+1);
                    }
                }
            }
        }

        return -1;
    }
};
