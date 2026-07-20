class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;

    TrieNode(){
        isWord = false;
        for(auto &i : child) i = nullptr;
    }
};

class Trie {

    TrieNode *root;
    bool dfs(TrieNode*nd, string &word, int id, int ct){

        if(!nd) return false;

        if(id == word.size()) return nd->isWord && !ct;

        bool ans = dfs(nd->child[word[id]-'a'], word, id+1, ct);
        // if(ans) return true;

        if(ct){
            for(int i=0; i<26; i++){
                if(i == word[id]-'a') continue;
                if(dfs(nd->child[i], word, id+1, 0)) return true;
            }
        }

        return ans;
    }

public:
    Trie() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* nd = root;
        for(auto &i : word){
            if(!nd->child[i-'a']) nd->child[i-'a'] = new TrieNode();
            nd = nd->child[i-'a'];
        }
        nd->isWord = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0, 1);
    }
};

class MagicDictionary {
    Trie trie;

public:
    MagicDictionary() {
        // trie = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &i : dictionary){
            trie.addWord(i);
        }
    }
    
    bool search(string searchWord) {
        return trie.search(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */