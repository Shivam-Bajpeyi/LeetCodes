class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;   
        while(!st.empty() && st.top().first<= price){
            span += st.top().second;   //add up consecutive small or equal days
            st.pop();
        }
        
        st.push({price, span});
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */