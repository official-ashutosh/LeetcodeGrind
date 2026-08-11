class Solution {
public:

    int par[1010], siz[1010];

    void ini(int v){
        par[v] = v;
        siz[v] = 1;
    }

    int find_par(int v){
        if(par[v] == v) return v;
        return par[v] = find_par(par[v]);
    }

    void merge(int a, int b){
        int par1 = find_par(a);
        int par2 = find_par(b);

        if(par1 != par2){

            int sz1 = siz[par1];
            int sz2 = siz[par2];
            if(sz1 < sz2) swap(par1, par2);

            siz[par1] += siz[par2];
            par[par2] = par1;
        }
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({sum, i, j});
            }
        }

        for(int i=0; i<n; i++) ini(i);

        sort(edges.begin(), edges.end());
        int ans = 0;
        for(auto ed : edges){
            int i = ed[1];
            int j = ed[2];
            int cst = ed[0];

            if(find_par(i) != find_par(j)){
                ans += cst;
                merge(i, j);
            }
        }

        return ans;
    }
};