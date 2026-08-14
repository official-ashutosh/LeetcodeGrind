class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ct = __builtin_popcount(num2);
        int ans = 0;

        for(int i=30; i>=0; i--){
            if(ct == 0) break;

            if(num1 & (1ll << i)){
                ans += (1ll << i);
                ct--;
            }
        }

        for(int i=0; i<=30; i++){
            if(ct == 0) break;

            if(!(num1 & (1ll << i))){
                ans += (1ll << i);
                ct--;
            }
        }

        return ans;
    }
};