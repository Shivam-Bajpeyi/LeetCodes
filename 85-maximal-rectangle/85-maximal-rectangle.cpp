//think each row as rectangle and solve it like largest rectangle.
//dp - as we are using previous colm to calc height for each row

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int mx = 0;
        stack<int> pse; //stores previous smaller element
        
        //find max area
        for(int i=0; i<=n; i++){
            //if current building is smaller, it will be right smaller for the top element
            // left smaller will be the value which was pushed before top();
            while(!pse.empty() && (i==n || heights[i]< heights[pse.top()]))  
            {
                int height = heights[pse.top()];
                pse.pop();  
                int width;
                
                if(pse.empty()) width = i;  //when there is no rs & ls width = index itself
                else  width = i- pse.top()-1; //rs- ls - 1; 
                
                mx = max(mx, height*width);
                // cout<<height<<" "<<height*width<<" "<<mx<<endl;
            }
            
            //push current index
            pse.push(i);
        }

        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        
        int maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            
            //after making height vector for each row pass it
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};