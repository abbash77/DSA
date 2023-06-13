class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int e=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=k){
                e=i;
                break;
            }
        }
        int i=0;
        int j=e;
        int ans=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                ans++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j]>k){
                j--;
            }
            else if(nums[i]+nums[j]<k){
                i++;
            }
        }
        return ans;
    }
};