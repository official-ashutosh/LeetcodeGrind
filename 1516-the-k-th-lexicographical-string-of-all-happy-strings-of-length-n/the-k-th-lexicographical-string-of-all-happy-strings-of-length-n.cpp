class Solution {
public:


    vector<string> v;
    vector<char> c = {'a', 'b', 'c'};
    string cr;
    void func(char p, int l, int n){
        if(l == n){
            v.push_back(cr);
            return;
        }

        for(auto i : c){
            if(i != p){
                cr += i;
                func(i, l+1, n);
                cr.pop_back();
            }
        }

    }

    string getHappyString(int n, int k) {
        func(' ', 0, n);
        if(k > v.size()) return "";
        return v[k-1];

        
    }
};