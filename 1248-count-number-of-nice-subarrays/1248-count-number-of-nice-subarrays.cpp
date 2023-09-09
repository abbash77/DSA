class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> d(nums.size()+1,1);
        int dis=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]%2==1){
                dis=1;
            }
            else{
                dis++;
            }
            d[i]=dis;
        }
        int ans=0;
        int cnt=0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2==1){
                cnt++;
            }
            while(i<=j&&cnt==k){
                ans+=d[j+1];
                if(nums[i]%2==1){
                    cnt--;
                }
                i++;
            }
        }
        return ans;
    }
};