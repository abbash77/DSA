class Solution {
public:
    long sumOfNum(long n){
        return (n*(n+1))/2;
    }
    int arrangeCoins(int n) {
        long s=0;
        long e=n;
        long ans;
        long mid=(s+e)/2;
        while(s<=e){
            long z=sumOfNum(mid);
            if(z>n){
                e=mid-1;
            }
            else if(z<=n){
                ans=mid;
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
};