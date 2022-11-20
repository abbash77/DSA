class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int no;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mini>=abs(nums[i]-0)){
                if(mini==abs(nums[i]-0)){
                    if(nums[i]>=0){
                        no=nums[i];
                    }
                    continue;
                }
                mini=abs(nums[i]-0);
                no=nums[i];
            }
        }
        return no;
    }
};