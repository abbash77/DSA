class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt=1;
        int maxi=INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                cnt++;
            }
            else{
                maxi=max(maxi,cnt);
                cnt=1;
            }
        }
        if(cnt!=0){
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};