class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        long long mid=s+(e-s)/2;
        long long ans;
        while(s<=e){
            if(mid*mid>x){
                e=mid-1;
            }
            else{
                s=mid+1;
                ans=mid;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};