class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int c1 = 0, c0 = 0;


        for(char c : s){
            if(c=='1') c1++;
            else c0++;
        }

        if(!c0) return 0; 
        if(k==1) return c0;
        if(k==n && c1) return -1; 
        if(k==c0) return 1; 


        for(int i=2; i<=n; i++) { 
            int tot = k*i;

            if(tot < c0) continue;

            if(tot % 2 != c0 % 2) continue;

            if(i & 1){
                if((n-k)*i < c1) continue;
            } else {
                if((n-k)*i < c0) continue;
            }


            return i;
        }


        return -1;
    }
};