class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k) return s;

        string t;
        int n = s.size();
        for(int i=0; i<n; i+=k){
            int sum = 0;
            
            for(int j=i; j<min(i+k,n); j++){
                sum += s[j]-'0';
            }
            
            t += to_string(sum);
        }

        cout << t << " ";

        return digitSum(t,k);
    }
};