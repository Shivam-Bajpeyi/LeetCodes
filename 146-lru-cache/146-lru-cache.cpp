class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
        
            node* prev;
            node* next;
        
            node(int _key, int _val){
                key = _key;
                val = _val;
            }   
    };
    
    //initial setup
    node* head = new node(0, 0);
    node* tail = new node(0, 0);
    
    int cap = -1;
    unordered_map<int, node*> mpp;  //key, node
    
    
    LRUCache(int capacity) {
        cap = capacity;   
        head->next = tail; tail->prev = head;
    }
    
    void deleteNode(int key){
        node* prv = mpp[key]->prev;
        node* nxt = mpp[key]->next;
        prv->next = nxt;
        nxt->prev = prv;        
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())  //if not present in map, -1
            return -1;
        
        //if it is there in map, go to the node and take the value
        int value = mpp[key]->val;
        
        //now this node is recemtly used, delete it and put just after the head
        //1) delete it
        deleteNode(key);
        
        //erase this (key, node) from map
        mpp.erase(key);
        
        //2) put a new node(key, value) just after head
        put(key, value);    //this will update the map too
        
        return value;
    }
    
   
    
    void put(int key, int value) {
        //if key is present in map, delete it from DLL & erase from map, then insert
        if(mpp.find(key) != mpp.end()){
            deleteNode(key);
            mpp.erase(key);
        }
        
        
        //if cap is full, delete least recent used node (tail->prev), then insert
        if(mpp.size()>= cap){
            mpp.erase(tail->prev->key);
            node* prv = tail->prev->prev;     
            tail->prev = prv;
            prv->next = tail;
        }
        
        //inserting new node just after head & (key, node) to map
        node* nw = new node(key, value);
        node* nxt = head->next; 
        
        // fit nw node btw head & nxt
        head->next = nw;
        nw->prev = head;
        nw->next = nxt;
        nxt->prev = nw;
        
        //store (key, node) to map
        mpp[key] = nw;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */