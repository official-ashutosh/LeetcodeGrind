class TrieNode {
public:
    TrieNode *child[2];
    int cnt;

    TrieNode(){
        cnt = 0;
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

    void insert(int x){
        TrieNode *nd = root;

        for(int i=30; i>=0; i--){
            int b = (x >> i) & 1;

            if(!nd->child[b])
                nd->child[b] = new TrieNode();

            nd = nd->child[b];
            nd->cnt++;
        }
    }

    void erase(int x){
        TrieNode *nd = root;

        for(int i=30; i>=0; i--){
            int b = (x >> i) & 1;
            nd = nd->child[b];
            nd->cnt--;
        }
    }

    int mx_xr(int x){
        TrieNode *nd = root;
        int ans = 0;

        for(int i=30; i>=0; i--){
            int b = (x >> i) & 1;
            int o = b ^ 1;

            if(nd->child[o] && nd->child[o]->cnt > 0){
                ans |= (1 << i);
                nd = nd->child[o];
            }
            else
                nd = nd->child[b];
        }

        return ans;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        Trie *t = new Trie();
        int ans = 0;
        int l = 0;

        for(int r=0; r<nums.size(); r++){
            t->insert(nums[r]);

            while((long long)nums[r] > 2LL * nums[l]){
                t->erase(nums[l]);
                l++;
            }

            ans = max(ans, t->mx_xr(nums[r]));
        }

        return ans;
    }
};