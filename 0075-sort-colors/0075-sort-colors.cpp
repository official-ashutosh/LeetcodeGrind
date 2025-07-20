class Solution {
public:
    void sortColors(vector<int>& a) {

        int n = a.size();
        int l = 0, r = n-1;
        int id = 0;

        while(id <= r){
            while(r >= 0 && a[r] == 2) r--;
            while(l < n && a[l] == 0) l++;

            while(l < r && a[r] == 0 && a[l] == 2){
                swap(a[r],a[l]);
                r--;
                l++;
            }

            while(id < l) id++;
            if(l >= n || r < 0 || l >= r) break;
            // cout << id << " ";
            
            if(a[id] == 0) swap(a[l], a[id]);
            else if(a[id] == 2) swap(a[r], a[id]);
            else id++;

        }


    }
};