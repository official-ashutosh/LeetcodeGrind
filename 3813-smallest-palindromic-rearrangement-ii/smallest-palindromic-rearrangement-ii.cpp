class Solution {
private:
    long long comb(long long n, long long m, long long k) {
        long long res = 1;
        m = min(m, n-m);

        for(long long i=1; i<=m; i++) {
            res = res * (n - i + 1) / i;
            if(res > k) {
                return k + 1;
            }
        }
        return res;
    }

public:
    string smallestPalindrome(string s, long long k) {
        int p = s.length() / 2;
        vector<int> bucket(26, 0);

        for (int i = 0; i < p; i++) {
            bucket[s[i] - 'a']++;
        }

        auto permutations = [&](int rem) {
            long long ways = 1;

            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0) continue;

                ways *= comb(rem, bucket[i], k);

                if (ways > k) break;

                rem -= bucket[i];
            }

            return ways;
        };

        string left;
        long long startIndex = 1;

        for (int pos = 0; pos < p; pos++) {
            for (int i = 0; i < 26; i++) {
                if (bucket[i] == 0) continue;

                bucket[i]--;

                long long ways = permutations(p - pos - 1);

                if (startIndex + ways > k) {
                    left += char(i + 'a');
                    break;
                }

                bucket[i]++;
                startIndex += ways;
            }
        }

        if (left.length() < p) {
            return "";
        }

        string mid =
            (s.length() & 1) ? string(1, s[p]) : "";

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};