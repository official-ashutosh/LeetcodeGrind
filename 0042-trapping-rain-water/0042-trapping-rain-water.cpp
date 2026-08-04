class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        int id = 0;
        for(auto i : height){
            if(!st.empty()){
                while(!st.empty() && i > height[st.top()]){
                    int top = st.top();
                    st.pop();
                    if(st.empty()) break;

                    int k = min(i, height[st.top()]) - height[top];
                    ans += (id-st.top()-1) * k;
                }
            }
            st.push(id);
            id++;
        }
        return ans;
    }
};
