class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;

    TrieNode(){
        isWord = false;
        for(auto &i : child) i = nullptr;
    }
};

class WordDictionary {

    TrieNode *root;
    bool dfs(TrieNode*nd, string &word, int id){

        if(!nd) return false;

        if(id == word.size()) return nd->isWord;

        if(word[id] != '.'){
            return dfs(nd->child[word[id]-'a'], word, id+1);
        }

        for(int i=0; i<26; i++){
            if(dfs(nd->child[i], word, id+1)) return true;
        }

        return false;
    }

public:
    WordDictionary() {
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
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */