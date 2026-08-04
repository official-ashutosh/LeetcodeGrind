class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0, 0, "", n, ans);
        return ans;        
    }

private:
    void dfs(int openP, int closeP, string s, int n, vector<string>& ans) {
        if(openP == closeP && openP + closeP == n * 2) {
            ans.push_back(s);
            return;
        }

        if(openP < n) {
            dfs(openP+1, closeP, s + "(", n, ans);
        }

        if(closeP < openP) {
            dfs(openP, closeP + 1, s + ")", n, ans);
        }
    }
};