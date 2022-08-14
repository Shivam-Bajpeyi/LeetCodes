class MinStack {
public:
    stack<pair<long, long>> st;
    int mn;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())      //consider first value as minimum
            mn = val;
        
        else if(val< mn)         //update mn in rest cases
            mn = val;
        
        st.push({val, mn});
    }
    
    void pop() {
        st.pop();
        if(!st.empty())
            mn = st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */