class Solution {
public:
    int mod = 1e9+7;
    long long mult(long long a,long long b){
        long long abhi=(a*b)%mod;
        return abhi;
    }
    long long exp(long long a,long long b){
        if(b==0)return 1;
        if(b==1)return a%mod;
        if(b&1){
            long long abhi=exp(a,b/2);
            return mult(mult(abhi,abhi),a);
        }
        else{
            long long abhi=exp(a,b/2);
            return mult(abhi,abhi);
        }
    }
    
    long long div(long long a,long long b){
        return mult(a,exp(b,mod-2));
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        //itne gap aur ye mod se start hone wali array hai kya
        map<pair<int,int>,vector<int>>mp;
        for(auto &x:queries){
            int l,r,k,v;
            l=x[0];
            r=x[1];
            k=x[2];
            v=x[3];
            if(mp.find({k,l%k})==mp.end()){
                mp[{k,l%k}]={};
                int st = l%k;
                while(st<n){
                    mp[{k,l%k}].push_back(1);
                    st+=k;
                }
            }
            int st=(l-(l%k))/k;
            int abhi=(r-(l%k))/k;
            r=(l%k)+(abhi)*k;
            int end=(r-(l%k))/k;
            mp[{k,l%k}][st]=mult(mp[{k,l%k}][st],v);
            if(end+1<mp[{k,l%k}].size()){
                mp[{k,l%k}][end+1]=div(mp[{k,l%k}][end+1],v);
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            vector<int>&now = (it->second);
            int m =now.size();
            for(int i=0;i<m;i++){
                if(i){
                    now[i]=mult(now[i],now[i-1]);
                }
            }
            for(int i=0;i<m;i++){
                int k=(it->first).first;
                int st=(it->first).second;
                int idx=st+(i)*k;
                nums[idx]=mult(nums[idx],now[i]);
            }
        }
        int fin=0;
        for(int i=0;i<n;i++){
            fin=fin^(nums[i]);
        }
        return fin;
        return 0;
    }
};
// 0 3 6 9 12
// 1 4 7. 8