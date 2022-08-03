class MyCalendar {
public:
    vector<pair<int, int>> vec;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        //if this new booking is occuring in between any event
        for(auto it: vec){
            if(max(start, it.first) < min(end, it.second))
                return false;
        }
        
        vec.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */