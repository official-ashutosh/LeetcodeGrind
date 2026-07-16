class StockSpanner {
public:

    vector<int> arr;
    stack<int> st;
    int i;
    StockSpanner() {
        i = -1;
    }
    
    int next(int price) {
        i++;
        arr.push_back(price);
        while(!st.empty() && arr[st.top()] <= price){
            st.pop();
        }

        int ans = i+1;
        if(!st.empty()) ans = i-st.top();
        st.push(i);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */