class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, set<int>> mp;

        for(auto &i : reservedSeats) {
            mp[i[0]].insert(i[1]);
        }

        int ans = 2*(n-mp.size());

        for(auto &[row, seats] : mp) {
            bool a = true, b = true, c = true;

            for(int i=2; i<=5; i++) {
                if(seats.count(i)) a = false;
            }

            for(int i=6; i<=9; i++) {
                if (seats.count(i)) b = false;
            }

            for(int i=4; i<=7; i++) {
                if (seats.count(i)) c = false;
            }

            if(a && b)
                ans += 2;
            else if (a || b || c)
                ans += 1;
        }

        return ans;
    }
};