class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> s;
        sort(folder.begin(), folder.end());

        for(auto i : folder){
            string tmp;
            int fl = 0;
            char prev='.';
            for(int j=0; j<i.size(); j++){
                tmp += i[j];
                while(j+1 < i.size() && i[j+1]!='/') {
                    tmp += i[j+1];
                    j++;
                }

                cout << tmp <<  " ";
                if(s.find(tmp) != s.end()){
                    fl = 1;
                    break;
                }
                // prev = j;
            }

            if(!fl) s.insert(i);
        }

        vector<string> ans;
        for(auto i : s) ans.push_back(i);

        return ans;
    }
};