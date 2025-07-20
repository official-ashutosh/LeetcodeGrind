class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto i : queries){
            int a = i[0];
            int b = i[1];

            int ans2 = 1;
            int p1 = a;
            int p2 = b;

            while(p1 != p2){
                if(p1 > p2){
                    p1 /= 2;
                } else {
                    p2 /= 2;
                }
            }

            while(a != p1){
                a /= 2;
                ans2++;
            }

            while(b != p2){
                b /= 2;
                ans2++;
            }

            ans.push_back(ans2);
        }

        return ans;
    }
};
