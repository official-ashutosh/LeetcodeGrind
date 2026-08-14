class TrieNode {
public:
    TrieNode *child[2];
    bool isWord;

    TrieNode(){
        isWord = false;
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Trie {
    TrieNode *root;

public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode *nd = root;

        for(auto &i : word){
            if(!nd->child[i-'0']) nd->child[i-'0'] = new TrieNode();
            nd = nd->child[i-'0'];
        }

        nd->isWord = true;
    }

    string mx_xr(string word){
        string ans;
        TrieNode *nd = root;

        for(auto &i : word){
            char c = (i == '0') ? '1' : '0';
            if(!nd->child[c-'0']) c = i;
            ans += c;
            nd = nd->child[c-'0'];
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<pair<pair<int,int>,int>> q;

        for(int i=0; i<queries.size(); i++)
            q.push_back({{queries[i][1], queries[i][0]}, i});

        sort(q.begin(), q.end());

        vector<int> ans(queries.size(), -1);

        Trie *t = new Trie();
        int j = 0;

        for(auto qq : q){
            int m = qq.first.first;
            int x = qq.first.second;
            int id = qq.second;

            while(j < nums.size() && nums[j] <= m) {
                string s;

                for(int i=30; i>=0; i--){
                    if((1LL<<i) & nums[j]) s += '1';
                    else s += '0';
                }

                t->insert(s);
                j++;
            }

            if(j == 0) continue;

            string s;

            for(int i=30; i>=0; i--){
                if((1ll<<i) & x) s += '1';
                else s += '0';
            }

            string s2 = t->mx_xr(s);

            int res = 0;

            for(int i=0; i<31; i++) {
                if(s[i] != s2[i])
                    res += (1LL << (30-i));
            }

            ans[id] = res;
        }

        return ans;
    }
};