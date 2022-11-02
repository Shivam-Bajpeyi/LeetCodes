class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>  st;
        
        int cnt = 0;
        //BFS
        queue<string> q;
        q.push(start);
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                string node = q.front();
                q.pop();
                
                if(node== end) return cnt;
                
                //check every possible string by replacing every char 
                for(int i=0; i<node.size(); i++){
                    for(auto ch: "ACGT"){
                        string str = node;
                        str[i] = ch;
                        if(!st.count(str) && find(bank.begin(), bank.end(), str) != bank.end()){
                            q.push(str);
                            st.insert(str);
                        }     
                    }
                }
            }
            cnt++;      //count the steps
        }
        
        return -1;
    }
};