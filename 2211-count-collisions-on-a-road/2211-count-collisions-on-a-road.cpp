class Solution {
public:
    int countCollisions(string directions) {
        int fl = 0, c = 0, ans = 0;

        for(auto i : directions){
            if(i == 'R') c++;
            else if(i == 'L'){
                if(c > 0) {
                    ans += c+1;
                    fl = 1;
                }
                else if(fl) {
                    ans++;
                    fl = 1;
                }
                c = 0;
                
            }
            else {
                ans += c;
                c = 0;
                fl = 1;
            }
        }

        return ans;
    }
};