class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        if(n == 1) return;
        int r = 0;
        for(int i=n-1; i>0; i--){
            if(a[i] > a[i-1]){
                r = i;
                break;
            }
        }

        if(r == 0) sort(a.begin(), a.end());
        else {
            int k = 0;
            for(int i=r; i<n; i++){
                if(a[i] > a[r-1]) k = i;
            }
            swap(a[k], a[r-1]);
            sort(a.begin()+r, a.end());
        }
    }
};