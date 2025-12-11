class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        map<int,int> mp1, mp2, mp3, mp4;
        
        for(auto i : b) {
            if(!mp1[i[0]] || i[1] < mp1[i[0]]) mp1[i[0]] = i[1];
            if(!mp2[i[0]] || i[1] > mp2[i[0]]) mp2[i[0]] = i[1];
            if(!mp3[i[1]] || i[0] < mp3[i[1]]) mp3[i[1]] = i[0];
            if(!mp4[i[1]] || i[0] > mp4[i[1]]) mp4[i[1]] = i[0];
        }
        
        int ans = 0;
        for(auto i : b) {
            if(mp1[i[0]] < i[1] && mp2[i[0]] > i[1] && mp3[i[1]] < i[0] && mp4[i[1]] > i[0]) ans++;
        }
        return ans;
    }
};
