/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */


//binary search
class Solution {
public:
    int guessNumber(int n) {
        long long lo= 1, hi = n;
        
        while(lo<=hi){
            long long mid = (lo+hi)>>1;
            // cout<<mid<<" ";
            long long result = guess(mid);
            
            if(result==0) return mid;
            else if(result==-1)         //guess is higher, shrink it
                hi = mid-1;
            else
                lo = mid+1;             //guess is lower, go right
        }
        
        return -1;
    }
};