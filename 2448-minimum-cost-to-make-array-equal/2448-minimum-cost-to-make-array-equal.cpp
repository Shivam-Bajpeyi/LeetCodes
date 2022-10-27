//select the median element to convert left and right elements to median
//median element  = sum of all costs/2
class Solution {
public:
    long long costToEqual(vector<int>& nums, vector<int>& cost, int median){
        long long res = 0;
        
        for(int i=0; i<nums.size(); i++){
            res += abs(1ll*median- 1ll*nums[i]) * 1ll*cost[i];
        }
        
        return res;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> vec;
        for(int i=0; i<nums.size(); i++){
            vec.push_back({nums[i], cost[i]});
        }
        
        sort(vec.begin(), vec.end());   //sort in increasing (num, cost) pair
        
        //total sum
        long long sum = 0;
        for(auto &it: vec)
            sum += 1ll*it.second;
        
        //median- take the element till that we have median sum
        long long i=0, total = 0, median= -1;
        while(total< (sum+1)/2 && i<vec.size()){
            total += 1ll*vec[i].second;
            median = vec[i].first;
            i++;
        }
            
        return costToEqual(nums, cost, median);
    }
};