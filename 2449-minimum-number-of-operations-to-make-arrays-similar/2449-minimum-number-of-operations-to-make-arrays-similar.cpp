//solve even and odd parity seperately
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        //convert nums -> target greeddily
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        
        vector<int> odd1, even1, odd2, even2;
        for(auto &it: nums){
            if(it%2==0) even1.push_back(it);
            else odd1.push_back(it);
        }
        for(auto &it: target){
            if(it%2==0) even2.push_back(it);
            else odd2.push_back(it);
        }
        
        long long count = 0;
        //even1 -> even 2 & odd1 -> odd2
        for(int i=0; i<odd1.size(); i++)
            count += 1ll* abs(odd1[i]- odd2[i])/2;     //count the difference to convert
        
        for(int i=0; i<even1.size(); i++)
            count += 1ll* abs(even1[i]- even2[i])/2;
        
        //half the ops
        return count/2;
    }
};