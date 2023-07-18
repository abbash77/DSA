class Solution {
public:
    bool isPossible(int mid,vector<int> nums,int m){
        int sum=0;
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
                k++;
                if(k==m||nums[i]>mid){
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
        }
        int s=0;
        int e=sum;
        int ans;
        int mid=(s+e)/2;
        while(s<=e){
            if(isPossible(mid,nums,m)){
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