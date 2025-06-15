class Solution {
public:
    int maxDiff(int num) {
        int id = -1;

        string s = to_string(num);
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i] != '9'){
                id = i;
                break;
            }
        }

        string mx = s;
        if(id != -1){
            for(int i=0; i<n; i++){
                if(mx[i] == s[id]) mx[i] = '9';
            }
        }

        id = -1;
        string mn = s;
        if(s[0] != '1'){
            id = 0;

            for(int i=0; i<n; i++){
                if(mn[i] == s[id]){
                    mn[i] = '1';
                }
            }

        } else {
            for(int i=1; i<n; i++){
                if(s[i] != '0' && s[i] != '1'){
                    id = i;
                    break;
                }
            }

            if(id != -1){
                for(int i=0; i<n; i++){
                    if(mn[i] == s[id]){
                        mn[i] = '0';
                    }
                }
            }
        }


        int ans = stoi(mx) - stoi(mn);

        return ans;

        

        
    }
};