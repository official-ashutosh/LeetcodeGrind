class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 > 0 && num2 > 0){
            if(num1 > num2){
                int p = num1/num2;
                ans += p;
                num1 -= (p*num2);
            } else {
                int p = num2/num1;
                ans += p;
                num2 -= (p*num1);
            }
        }

        return ans;
    }
};