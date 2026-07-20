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
    TrieNode* root;
public:

    Trie() {
       root = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* nd = root;

        for(auto &i : word){
            if(!nd->child[i-'a']) nd->child[i-'a'] = new TrieNode();
            nd = nd->child[i-'a'];
        }

        nd->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* nd = root;
        for(auto &i : word){
            if(!nd->child[i-'a']) return false;
            nd = nd->child[i-'a'];
        }

        return nd->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* nd = root;
        for(auto &i : prefix){
            if(!nd->child[i-'a']) return false;
            nd = nd->child[i-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */