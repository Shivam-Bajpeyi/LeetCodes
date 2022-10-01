class LUPrefix {
public:
    vector<int> nums;
    int prefix= 0;
    
    LUPrefix(int n) {
        nums.resize(n, 0);
    }
    
    void upload(int video) {
        nums[video-1]++;
    }
    
    int longest() {
        while(prefix < nums.size()){
            if(nums[prefix] == 1)
                prefix++;
            else
                break;
        }
        
        return prefix;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */