class StockSpanner {
public:
    stack<int> st;
    vector<int> arr;
    int totalindex=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        while(!st.empty() && arr[st.top()]<=price)
        {
            st.pop();
        }
        int ans=(st.empty()?totalindex+1:totalindex-st.top());
        st.push(totalindex);
        totalindex++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */