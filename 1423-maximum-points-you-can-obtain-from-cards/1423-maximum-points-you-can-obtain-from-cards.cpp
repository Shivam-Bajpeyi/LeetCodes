class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), ans = 0, window = 0;
        for(int i=n-1; i>=n-k; i--)
        {
            window += cardPoints[i];
        }
        
        ans = window;
        
        for(int i=0; i<k; i++)
        { 
            window = window+cardPoints[i]-cardPoints[n-k+i];
            ans = max(ans, window);
        }
        
        return ans;
    }
};