class Solution {
public:
    int n,m;
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]==word[0]){
                    if(dfs(board,vis,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,string& word,int i,int j,int k){
       
        if(i<0|| i>=n|| j<0 || j>=m ||board[i][j]!=word[k] || vis[i][j]) return false;
        if(k==word.size()-1) return true;
        vis[i][j]=true;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int a=0;a<4;a++){
            if(dfs(board,vis,word,i+dx[a],j+dy[a],k+1)) return true;
        }
        vis[i][j]=false;
        return false;
    }
};