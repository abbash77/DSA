class Solution {
public:
    bool isPossible(vector<int>& piles,int h,int mid){
        long long sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=ceil(double(piles[i])/mid);
        }
        if(sum<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=1000000000;
        int mid=(s+e)/2;
        int ans;
        while(s<=e){
            if(isPossible(piles,h,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
};