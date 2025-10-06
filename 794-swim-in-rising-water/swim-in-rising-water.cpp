class Solution {
public:

    int parent[2510], siz[2510];

    void make_set(int v) {
        parent[v] = v;
        siz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (siz[a] < siz[b])
                swap(a, b);
            parent[b] = a;
            siz[a] += siz[b];
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int n = grid.size();
        int l = 0, r = n*n-1;
        int ans = 0;

        while(l <= r){
            int mid = (l+r)/2;

            for(int i=0; i<n*n; i++) make_set(i);
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j] <= mid){
                        for(auto di : dir){
                            int nx = i + di.first;
                            int ny = j + di.second;

                            if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] <= mid){
                                union_sets(i*n+j, nx*n+ny);
                            }
                        }
                    }
                }
            }

            if(find_set(0) == find_set(n*n-1)){
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return ans;
    }
};