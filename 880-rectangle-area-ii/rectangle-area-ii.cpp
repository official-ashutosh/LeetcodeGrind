class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9 + 7;
        set<int> x_set, y_set;

        for (auto& rect : rectangles) {
            x_set.insert(rect[0]);
            x_set.insert(rect[2]);
            y_set.insert(rect[1]);
            y_set.insert(rect[3]);
        }

        vector<int> x_coords(x_set.begin(), x_set.end());
        vector<int> y_coords(y_set.begin(), y_set.end());

        vector<vector<bool>> grid(x_coords.size(), vector<bool>(y_coords.size(), false));

        long long ans = 0;

        for (auto& rect : rectangles) {
            int x1 = lower_bound(x_coords.begin(), x_coords.end(), rect[0]) - x_coords.begin();
            int x2 = lower_bound(x_coords.begin(), x_coords.end(), rect[2]) - x_coords.begin();
            int y1 = lower_bound(y_coords.begin(), y_coords.end(), rect[1]) - y_coords.begin();
            int y2 = lower_bound(y_coords.begin(), y_coords.end(), rect[3]) - y_coords.begin();

            for (int i = x1; i < x2; ++i) {
                for (int j = y1; j < y2; ++j) {
                    if (!grid[i][j]) {
                        grid[i][j] = true;
                        long long width = x_coords[i + 1] - x_coords[i];
                        long long height = y_coords[j + 1] - y_coords[j];
                        ans = (ans + width * height) % MOD;
                    }
                }
            }
        }

        return ans;
    }
};
