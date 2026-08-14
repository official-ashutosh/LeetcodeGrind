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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        Trie *t = new Trie();
        for(auto i : nums){
            string s; 
            for(int j=30; j>=0; j--){       
                if(i & (1ll<<j)) s += '1';
                else s += '0';
            }

            t->insert(s);
        }   

        int ans = 0;
        for(auto i : nums){
            string s; 
            for(int j=30; j>=0; j--){      
                if(i & (1ll<<j)) s += '1';
                else s += '0';
            }

            string s2 = t->mx_xr(s);
            int ans2 = 0;

            for(int j=0; j<31; j++){
                if(s[j] != s2[j])
                    ans2 += (1ll << (30-j));
            }

            ans = max(ans, ans2);
        }

        return ans;
    }
};