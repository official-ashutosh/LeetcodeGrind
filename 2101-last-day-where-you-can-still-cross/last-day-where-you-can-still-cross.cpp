class Solution {
public:

    static const int N = 1e5+10;

    int parent[N], siz[N];

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

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row*col;
        int top = n+1, bot = n+2;
        for(int i=1; i<=n+2; i++) make_set(i);

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
        vector<vector<int>> a(row, vector<int> (col, 1));

        for(int i=cells.size()-1; i>=0; i--){
            int r = cells[i][0]-1;
            int c = cells[i][1]-1;
            a[r][c] = 0;

            for(auto k : dir){
                int x = r + k.first;
                int y = c + k.second;

                if(x >= 0 && y >= 0 && x < row && y < col && a[x][y] == 0){
                    union_sets(r*col + c + 1, x*col + y + 1);
                }
            }

            if(r == 0) union_sets(r*col + c + 1, top);
            if(r == row-1) union_sets(r*col + c + 1, bot);

            if(find_set(top) == find_set(bot)) return i;
        }

        return 0;
    }
};
