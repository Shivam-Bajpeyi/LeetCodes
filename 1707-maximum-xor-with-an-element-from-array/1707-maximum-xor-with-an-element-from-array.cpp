struct Node{
    Node* links[2];
    
    bool containsBit(int bit){
        return (links[bit]!= NULL);
    }
    
    void put(int bit, Node* node){
        links[bit] = node;
    }
    
    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private: 
    Node* root;
    
    public:
    Trie(){
      root = new Node();
    }
    
    void insert(int num){
        Node* node = root;
        
        for(int i=31; i>=0; i--){
            int bit = ((num>>i) & 1);
            if(!node->containsBit(bit)){
                node->put(bit, new Node());
            }
            
            node = node->get(bit);
        }
    }
    
    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        
        for(int i=31; i>=0; i--){
            int bit = ((num>>i) & 1);       //bit at ith bit
            
            //if opposite bit is present
            if(node->containsBit(1- bit)){
                maxNum = maxNum | (1<<i);    //place 1 at ith place in maxNum
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        
        return maxNum;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int,int>>> oq;         
        
        for(int i=0; i<queries.size(); i++)
            oq.push_back({queries[i][1], {queries[i][0], i}});
        
        //sort oq acc to i[1] so that we can process query by storing vector elements one by one
        sort(oq.begin(), oq.end());
    
        
        Trie* trie = new Trie();
        //process queries
        vector<int> res(queries.size());
        int j =0;
        for(auto &it: oq){                                 //it = [Mi, {ai, sn}]
            while(j<nums.size() &&  nums[j] <= it.first){
                trie->insert(nums[j++]);
            }
                
            
            if(j==0)
                res[it.second.second] = -1;
            else
                res[it.second.second] = trie->getMax(it.second.first);
                
        }
        
        return res;
    }
};