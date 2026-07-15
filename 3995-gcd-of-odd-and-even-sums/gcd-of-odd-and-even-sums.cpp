class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sm1 = n*n;
        int sm2 = (n*(2*n+1)) - sm1;

        int ans = __gcd(sm1, sm2);
        return ans;
    }
};