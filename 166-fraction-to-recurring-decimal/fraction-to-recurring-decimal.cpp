class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";

        string ans = "";
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) ans += '-';

        long num = labs(numerator), den = labs(denominator);

        long k = num/den;
        long r = num % den;

        ans += to_string(k);

        if(r == 0) return ans;

        ans += '.';

        unordered_map<long, int> mp;
        while(r != 0){
            if(mp.find(r) != mp.end()){
                ans.insert(mp[r], "(");
                ans += ')';
                break;
            }

            mp[r] = ans.length();
            r *= 10;
            k = r/den;
            r %= den;
            ans += to_string(k);
        }

        return ans;

    }
};