class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for(int i=0; i<num.size()-2; i++){
            if(num[i] == num[i+1] && num[i+1] == num[i+2]){
                string t = "";
                t += num[i];
                t += num[i];
                t += num[i];
                ans = max(ans, t);
            }
        }

        return ans;
    }
};