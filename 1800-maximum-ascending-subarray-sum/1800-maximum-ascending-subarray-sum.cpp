class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1&&nums[i-1]<nums[i]){
                sum+=nums[i];
                maxi=max(maxi,sum);
            }
            else if(i==nums.size()-1&&nums[i-1]>=nums[i]){
                maxi=max(maxi,nums[i]);
            }
            else{
                if(nums[i]<nums[i+1]){
                    sum+=nums[i];
                }
                else{
                    sum+=nums[i];
                    maxi=max(maxi,sum);
                    sum=0;
                }
            }
            
        }
        return maxi;
    }
};