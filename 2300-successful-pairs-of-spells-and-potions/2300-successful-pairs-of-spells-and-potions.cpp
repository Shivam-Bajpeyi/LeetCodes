class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        vector<int> res;
        int n = potions.size();
        sort(potions.begin(), potions.end());
        
        for (auto& spell : spells) {
            int start = 0, end= n-1;
            int mid;
            while (start <= end) {
                mid = (start + end)>>1;
                if((long long)spell*potions[mid] >= success)
                    end = mid-1;
                else
                    start = mid+1;
            }
            
            res.push_back(n-start);
        }
        return res;
    }
};