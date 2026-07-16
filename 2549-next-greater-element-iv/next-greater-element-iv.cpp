class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int  n = nums.size();

        stack<int> st, st2, tp;
        vector<int> nxt(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                nxt[st.top()] = nums[i];
                st.pop();
            }

            while(!st2.empty() && nums[st2.top()] < nums[i]){
                tp.push(st2.top());
                st2.pop();
            }

            while(!tp.empty()){
                st.push(tp.top());
                tp.pop();
            }
            st2.push(i);

        }

        return nxt;
    }
};