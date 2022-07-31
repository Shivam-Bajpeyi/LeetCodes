class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int sum = 1;    //count number of elements picked
        int k = 1;      //count sets
        
        //if we sort elements, both conditions will be satisfied. We just need to pick elements like 1, 2, ..
        //take number of elements: 1, 2, 3, 4, 5... untill total elements picked <= n
        while(sum +k+1 <=n) //after 1 can 2 elements be picked
            sum += ++k;     //add up elements picked 1+2 = 3
        
        return k;
    }
};