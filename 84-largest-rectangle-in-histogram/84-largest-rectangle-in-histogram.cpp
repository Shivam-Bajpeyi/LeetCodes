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
                
                if(pse.empty()) width = i;
                else  width = i- pse.top()-1; //rs- ls - 1; 
                
                mx = max(mx, height*width);
                cout<<mx<<endl;
            }
            
            //push current index
            pse.push(i);
        }

        return mx;
    }
};