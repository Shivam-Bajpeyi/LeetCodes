class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int ans = -1;
        
        //if s2 is empty fill from s1 to it
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        ans = s2.top();
        s2.pop();
        
        return ans;
        
    }
    
    int peek() {
        int ans = -1;
        
        //if s2 is empty fill from s1 to it
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        ans = s2.top();
        return ans;
        
    }
    
    bool empty() {
        return (s1.size()+s2.size())==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */