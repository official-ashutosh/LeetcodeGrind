class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long ans = 0;
        
        while(k > 1){
            int p = 0;

            while((1LL<<p) < k) p++;
            p--;

            k -= (1LL<<p);

            if(operations[p]) ans = (ans+1)%26;
        }

        return ('a'+ans);



    }
};