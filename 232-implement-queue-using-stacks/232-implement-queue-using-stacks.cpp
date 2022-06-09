class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int res = -1;   //when nothing left to return
        if(!output.empty()){    //if output is has elements pop from there.
            res = output.top();
            output.pop();
            return res;
        }
        
        //when output got empty, move all elements of input to output (st1->st2)
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        
        res= output.top();
        output.pop();
        return res;
    }
    
    int peek() {
        int res = -1;   //when nothing left to return
        if(!output.empty()){    //if output is has elements pop from there.
            res = output.top();
            return res;
        }
        
        //when output got empty, move all elements of input to output (st1->st2)
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        
        res= output.top();
        return res;
    }
    
    bool empty() {
        return (input.empty() && output.empty());
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