class Solution {
public:
    bool canAliceWin(int n) {
        int c = 10, fl = 0;
        while(true){
            if(n < c) return fl;
            n -= c;
            c--;
            fl ^= 1;
        }

        return true;
    }
};