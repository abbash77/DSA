/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long s=1;
        long e=n;
        long mid=(s+e)/2;
        int ans;
        while(s<=e){
            if(guess(mid)==0){
                ans= mid;
                break;
            }
            else if(guess(mid)==-1){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=(s+e)/2;
            
        }
        return ans;
    }
};