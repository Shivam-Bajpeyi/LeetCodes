class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> first, last;
        long long cost = 0;
        
        //store candidate number of elements from start and end
        int i=0, j= costs.size()-1, cnt= 0;
        while(k--){
            while(i<=j && first.size()<candidates)
                first.push(costs[i++]);
            while(i<=j && last.size()<candidates)
                last.push(costs[j--]);
            
            int a = (first.size()==0)? INT_MAX: first.top();
            int b = (last.size()==0)? INT_MAX: last.top();
            
            // cout<<a<<" "<<b<<endl;
            if(a<=b){
                cost += a;
                first.pop();
            }
            else{
                cost += b;
                last.pop();
            }
        }
        
        return cost;
    }
};