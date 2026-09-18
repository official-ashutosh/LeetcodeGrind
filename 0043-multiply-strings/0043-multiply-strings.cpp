class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> v(n+m, 0);

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int mul = (num1[i]-'0')*(num2[j]-'0');

                int pos1 = i+j+1;
                int pos2 = i+j;

                int sum = mul + v[pos1];

                v[pos1] = sum % 10;
                v[pos2] += sum / 10;
            }
        }

        string ans;
        int i = 0;

        while(i < v.size() && v[i] == 0)
            i++;

        while(i < v.size())
            ans += char('0'+v[i++]);

        return ans;
    }
};