class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=INT_MIN;
        int z=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                z++;
            }
            else{
                maxi=max(maxi,z);
                z=0;
            }
        }
        if(z!=0){
            maxi=max(maxi,z);
        }
        return maxi;
    }
};