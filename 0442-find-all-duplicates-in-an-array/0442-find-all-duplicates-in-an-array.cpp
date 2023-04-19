class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                if(nums[-1*nums[i]-1]<0){
                    ans.push_back(-1*nums[i]);
                }
                nums[-1*nums[i]-1]=nums[-1*nums[i]-1]*-1;
            }
            else{
                if(nums[nums[i]-1]<0){
                    ans.push_back(nums[i]);
                }
                nums[nums[i]-1]=nums[nums[i]-1]*-1;
            }
        }
        return ans;
    }
};