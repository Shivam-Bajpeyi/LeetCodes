class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto &it: piles)
            pq.push(it);
        
        //take top k element
        while(k--){
            int topp = pq.top();
            pq.pop();
            
            pq.push((topp+1)/2);
        }
        
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};