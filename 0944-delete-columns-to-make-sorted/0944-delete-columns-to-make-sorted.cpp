class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        //single word, nothing to compare with to make col sorted
        if(strs.size()==1) return 0;
        
        int cnt = 0;
        //col
        for(int i=0; i<strs[0].size(); i++){
            //row
            for(int j=1; j<strs.size(); j++){
                //if the small letter coming after bigger letter
                if(strs[j][i] < strs[j-1][i]){
                    cnt++;
                    break;  //move to next col
                }
            }
        }
        
        return cnt;
    }
};