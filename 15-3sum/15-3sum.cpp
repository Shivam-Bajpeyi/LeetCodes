class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;     //avoid ith duplicate

            //apply 2 pointer to get target
            int j= i+1, k =n-1;
            while(j<k){
                vector<int> temp;
                while(j>i+1 && j<k && nums[j]==nums[j-1]) j++;    //avoid jth duplicate 
                while(k<n-1 && j<k && nums[k]==nums[k+1]) k--;    //avoid kth duplicate
                if(j>=k) break;
                int sum = nums[i]+nums[j]+ nums[k];
                if(sum==0){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    ans.push_back(temp);
                    j++; k--;
                }
                else if(sum< 0)
                    j++;
                else
                    k--;
            }
            
        }
        
        return ans;
    }
};