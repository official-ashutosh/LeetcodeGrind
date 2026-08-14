class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    int cnt;

    TrieNode(){
        isWord = false;
        cnt = 0;
        for(auto &i : child) i = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:

    Trie() {
       root = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* nd = root;

        for(auto &i : word){
            if(!nd->child[i-'a'])
                nd->child[i-'a'] = new TrieNode();

            nd = nd->child[i-'a'];
            nd->cnt++;
        }

        nd->isWord = true;
    }
    
    int score(string word){
        int ans = 0;

        TrieNode *nd = root;   
        for(auto i : word){
            nd = nd->child[i-'a'];
            ans += nd->cnt;
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;

        for(auto &word : words)
            t.insert(word);

        vector<int> ans;

        for(auto &word : words){
            int res = t.score(word);

            ans.push_back(res);
        }

        return ans;
    }
};