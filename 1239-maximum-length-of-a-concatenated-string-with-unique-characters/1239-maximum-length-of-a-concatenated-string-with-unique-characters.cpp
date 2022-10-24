class Solution {
public:
    bool isUnique(string &a, string &b){
        unordered_map<char, int> mpp;
        for(auto it: a)
            mpp[it]++;
        
        //check duplicacy
        for(int i=0; i<a.size(); i++){
            if(mpp[a[i]]>1) return false;       //no duplicate in a itself
            
            for(int j=0; j<b.size(); j++){      //no same char in a & b
                if(a[i]==b[j]) return false;
            }
        }
        
        return true;
    }
    
    int f(int ind, vector<string> &arr, string s){
        if(ind==0){
            // cout<<arr[ind]+s<<" ";
            if(isUnique(arr[ind], s)){
                cout<<arr[ind]+s<<" ";
                return (arr[ind]+s).size();
            }
                
            return s.size();
        }
        
        //explore- subsequemce=> pick/notPick
        int pick = 0;
        if(isUnique(arr[ind], s)){
            pick = f(ind-1, arr, arr[ind]+s);
        }
            
        int notPick = f(ind-1, arr, s);
        
        return max(pick, notPick);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        
        return f(n-1, arr, "");
    }
};