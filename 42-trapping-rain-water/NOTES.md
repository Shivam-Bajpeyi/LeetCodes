​
1. brute I- calculate leftmax, and rightmax manually for each index | tc = O(N^2)
2. brute II- by making prefix & suffix vector for finding leftmax, rightmax | tc = O(3N), sc = O(1)
min(left[i], right[i])- height[i];
​
3. Optimal- 2 pointers | tc = O(N), sc = O(1)
step-1: l = start, r = end
step-2: find which side is smaller, update that side & find the stored water.***
​