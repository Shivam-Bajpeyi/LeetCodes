class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;   //stores freq of elements
        unordered_map<int, int> end;    //stores freq of last element of each subsequence
        
        for(auto &it: nums)
            freq[it]++;     //store freq initially
        
        //make subsequence
        for(auto &it: nums){
            if(freq[it]==0) continue;   //element is not there to make subseq
            
            freq[it]--; //using it to make subseq
            
            // cout<<end[it]<<" ";
            if(end[it-1]>0){    //if element can be added in the last of subseq
                end[it-1]--;
                end[it]++;
            }
            
            else if(freq[it+1]>0 && freq[it+2]>0){
                freq[it+1]--;
                freq[it+2]--;
                end[it+2]++;      //add freq of last element of the subseq
            }
            
            else{
                                // cout<<it<<endl;
                return false;

            }    //neither can be added to existing or new subseq
                
        } 
        
        //if all array elements can be split into valid subsequences 
        return true;
    }
};