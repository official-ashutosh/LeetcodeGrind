class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int sum = 0, res = 0;
        for(auto i : satisfaction){
            sum += i;
            if(sum < 0) break;

            res += sum;
        }

        return res;
    }
};