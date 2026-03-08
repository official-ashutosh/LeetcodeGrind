class Solution {
public:

    vector<string> v;
    vector<char> c = {'0', '1'};
    string cr;
    void func(int l, int n){
        if(l == n){
            v.push_back(cr);
            return;
        }

        for(auto i : c){
            cr += i;
            func(l+1, n);
            cr.pop_back();
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        func(0, n);
        for(auto i : v){
            if(!binary_search(nums.begin(), nums.end(), i)) return i;
        }
        return "";
    }
};