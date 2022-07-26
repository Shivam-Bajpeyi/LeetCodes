class MyStack {
public:
    queue<int> que;
    MyStack() {
        
    }
    
    void push(int x) {
        int n = que.size();
        que.push(x);
        
        //pop n elements and push it again to keep x at front
        while(n--){
            int temp = que.front(); que.pop();
            que.push(temp);
        }
        
    }
    
    int pop() {
        int ans = que.front();
        que.pop();
        return ans;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */