class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        if(minK>maxK){
            return 0;
        }
        int n=nums.size();
        vector<long long> d(n+1,1);
        long long dis=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>=minK&&nums[i]<=maxK){
                dis++;
            }
            else{
                dis=1;
            }
            d[i]=dis;
        }
        long long maxCount=0;
        long long minCount=0;
        int i=0;
        long long ans=0;
        for(int j=0;j<n;j++){
            if(nums[j]==minK){
                minCount++;
            }
            else if(nums[j]>maxK||nums[j]<minK){
                minCount=0;
                maxCount=0;
                i=j+1;
                
            }
            if(nums[j]==maxK){
                maxCount++;
            }
            while(i<=j&&maxCount>=1&&minCount>=1){
                ans+=d[j+1];
                if(nums[i]==maxK){
                    maxCount--;
                }
                if(nums[i]==minK){
                    minCount--;
                }
                i++;
            }
        }
        return ans;
    }
};