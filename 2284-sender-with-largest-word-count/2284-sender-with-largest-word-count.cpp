class Solution {
public:
    int countWords(string sentence){
        int words = 1;
        
        //count words in each sentence: space+1
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i]== ' ')
                words++;
        }
        return words;
    }
    
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        
        //step-1: count words for each message
        vector<int> count; 
        for(int i=0; i<n; i++){
            count.push_back(countWords(messages[i]));
        }
        
        //step-2: use hashmap to count total number of words for each sender 
        unordered_map<string, int> mpp;
        for(int i=0; i<n; i++)
            mpp[senders[i]] += count[i];
        
        //step-3: push (count, sender) to priority queue to get largest word count sender
        priority_queue<pair<int, string> > pq;
        
        for(auto it: mpp){
            pq.push({it.second, it.first});
        }
        
        return pq.top().second;
        
    }
};